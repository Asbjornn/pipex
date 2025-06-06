/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_pipex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 09:32:13 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/06 14:01:28 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

/* ======================================================================== */
/*									GET PATH								*/
/* ======================================================================== */

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

/* ======================================================================== */
/*								GET ABSOLUTE PATH							*/
/* ======================================================================== */

char	*ft_find_absolute_path(char *path, char **cmd)
{
	char	*command;
	char	**path_split;
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = NULL;
	command = NULL;
	if (!ft_strncmp(path, "PATH=", 5))
		path += 5;
	path_split = ft_split(path, ':');
	while (path_split[i])
	{
		tmp = ft_strjoin(path_split[i], "/");
		command = ft_strjoin(tmp, cmd[0]);
		free(tmp);
		if ((access(command, X_OK)) == 0)
			break ;
		free(command);
		command = NULL;
		i++;
	}
	free_tab(path_split);
	return (command);
}

/* ======================================================================== */
/*							GENERAL EXECUTE FUNCTION						*/
/* ======================================================================== */

static void	exec_cmd(char *argv[], char *envp[], int command_index)
{
	char	*abso;
	char	**cmd;
	char	*path;

	path = NULL;
	cmd = ft_split(argv[command_index], ' ');
	path = ft_get_path(envp);
	abso = ft_find_absolute_path(path, cmd);
	if (!abso)
	{
		free(path);
		free_tab(cmd);
		exit(127);
	}
	if (execve(abso, cmd, envp) == -1)
	{
		perror("execve failed, not existing command");
		free(abso);
		free(path);
		free_tab(cmd);
		exit(127);
	}
}

/* ======================================================================== */
/*									FIRST CHILD								*/
/* ======================================================================== */

void	first_child_process(char *argv[], int *end, char *envp[])
{
	int		f1;

	f1 = open(argv[1], O_RDONLY);
	if (f1 < 0)
	{
		perror("open file failed");
		exit(EXIT_FAILURE);
	}
	dup2(f1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	close(end[1]);
	close(f1);
	exec_cmd(argv, envp, 2);
}

/* ======================================================================== */
/*									SECOND CHILD							*/
/* ======================================================================== */

void	second_child_process(char *argv[], int *end, char *envp[])
{
	int		f2;

	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f2 < 0)
	{
		perror("open file failed");
		exit(EXIT_FAILURE);
	}
	dup2(end[0], STDIN_FILENO);
	dup2(f2, STDOUT_FILENO);
	close(end[1]);
	close(end[0]);
	close(f2);
	exec_cmd(argv, envp, 3);
}
