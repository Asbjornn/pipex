/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:37:17 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/13 17:44:05 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                          CHILD PROCESS GENERAL                           */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static void	child_process(char *cmd, char *envp[])
{
	pid_t	pid;
	int		end[2];

	pipe(end);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
	{
		close(end[0]);
		dup2(end[1], STDOUT_FILENO);
		close(end[1]);
		exec_cmd(cmd, envp);
	}
	else
	{
		close(end[1]);
		dup2(end[0], STDIN_FILENO);
		close(end[0]);
		waitpid(pid, NULL, 0);
	}
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                       CHILD PROCESS FOR HERE_DOC                         */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static void	child_here_doc(int end[2], char *limiter)
{
	char	*line;

	limiter[ft_strlen(limiter)] = '\0';
	line = get_next_line(0);
	while (line != NULL)
	{
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& ft_strncmp(line, limiter, ft_strlen(line) - 1) == 0)
		{
			free(line);
			exit(1);
		}
		write(end[1], line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
	}
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                              HERE_DOC HANDLE                             */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static void	here_doc(char *limiter)
{
	int		end[2];
	pid_t	pid;

	pipe(end);
	pid = fork();
	if (pid == 0)
	{
		close(end[0]);
		child_here_doc(end, limiter);
	}
	else
	{
		close(end[1]);
		dup2(end[0], STDIN_FILENO);
		close(end[0]);
		waitpid(pid, NULL, 0);
	}
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                  MAIN                                    */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

int	main(int argc, char *argv[], char *envp[])
{
	int		out;
	int		in;
	int		command;

	if (argc < 5)
		warning_format();
	if (strncmp(argv[1], "here_doc", 8) == 0)
	{
		command = 3;
		out = open(argv[argc - 1], O_CREAT | O_RDWR | O_APPEND, 0644);
		here_doc(argv[2]);
	}
	else
	{
		command = 2;
		in = open(argv[1], O_RDONLY);
		out = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
		dup2(in, STDIN_FILENO);
	}
	while (command < argc - 2)
		child_process(argv[command++], envp);
	dup2(out, STDOUT_FILENO);
	exec_cmd(argv[argc - 2], envp);
}
