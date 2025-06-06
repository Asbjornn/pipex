/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:10:39 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/05 18:04:24 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "test.h"

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*ft_get_path(char *envp[])
{
	size_t	i;
	char	*path;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (!ft_strncmp("PATH=", envp[i], 5))
		{
			path = ft_strdup(envp[i]);
			break ;
		}
		i++;
	}
	return (path);
}

char	*ft_find_absolute_path(char *path, char **cmd)
{
	char	*command;
	char	*abso_path;
	char	**path_split;
	char	*tmp;
	size_t	i;

	i = 0;
	abso_path = NULL;
	tmp = NULL;
	if (!ft_strncmp(path, "PATH=", 5))
		path += 5;
	path_split = ft_split(path, ':');
	while (path_split[i])
	{
		tmp = ft_strjoin(path_split[i], "/");
		command = ft_strjoin(tmp, cmd[0]);
		free(tmp);
		if ((access(command, X_OK)) == 0)
		{
			abso_path = ft_strdup(command);
			free(command);
			break ;
		}
		i++;
		free(command);
	}
	free_tab(path_split);
	return (abso_path);
}

void	child_process(char *argv[], int *end, char *env[])
{
	char	*path;
	char	**cmd;
	char	*abso_path;
	int		f1;

	f1 = open(argv[1], O_RDONLY);
	cmd = ft_split(argv[2], ' ');
	path = ft_get_path(env);
	abso_path = ft_find_absolute_path(path, cmd);
	if (!abso_path)
		exit(127);
	dup2(f1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	close(end[1]);
	close(f1);
	if (execve(abso_path, cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
		free_tab(cmd);
		exit(0);
	}
}

void	parent_process(char *argv[], int *end, char *env[])
{
	char	*path;
	char	**cmd;
	char	*abso_path;
	int		f2;

	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	cmd = ft_split(argv[3], ' ');
	path = ft_get_path(env);
	abso_path = ft_find_absolute_path(path, cmd);
	if (!abso_path)
		exit(127);
	dup2(end[0], STDIN_FILENO);
	dup2(f2, STDOUT_FILENO);
	close(end[0]);
	close(end[1]);
	close(f2);
	if (execve(abso_path, cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
		free_tab(cmd);
		exit(0);
	}
}

int main(int argc, char *argv[], char *envp[])
{
	int		f1;
	int		f2;
	pid_t	pid;
	int		end[2];
	if(argc != 5)
		return (printf("error, pas assez ou trop d'argument\n"), 0);
	pipe(end);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if(pid == 0)
		child_process(argv, end, envp);
	waitpid(pid, NULL, 0);
	parent_process(argv, end, envp);
}
