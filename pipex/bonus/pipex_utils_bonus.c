/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:56:32 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/10 15:19:52 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                 GET PATH	                                */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

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

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                             GET ABSOLUTE PATH                            */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

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

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                          GENERAL EXECUTE FUNCTION                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void	exec_cmd(char *command, char *envp[])
{
	char	*abso;
	char	**cmd;
	char	*path;

	path = NULL;
	cmd = ft_split(command, ' ');
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

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                            FREE FUNCTION                                 */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

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

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                          WARGNING FUNCTION                               */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void	warning_format(void)
{
	char	*warning1;
	char	*warning2;

	warning1 = "format: ./pipex here_doc 'LIMITER' 'cmd1' 'cmd2' 'outfile'";
	warning2 = "format: ./pipex 'infile' 'cmd1' 'cmd2' ... 'cmdn' 'outfile'";
	ft_printf("%s\n", warning1);
	ft_printf("%s\n", warning2);
	exit(0);
}
