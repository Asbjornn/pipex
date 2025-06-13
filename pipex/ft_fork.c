/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 09:32:13 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/11 12:12:22 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                          GENERAL EXECUTE FUNCTION                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

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

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                               FIRST CHILD                                */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

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

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                SECOND CHILD                              */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

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
