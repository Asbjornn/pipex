/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 09:32:13 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/05 16:07:01 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
#include <stdio.h>

void	first_child_process(int f1, char **cmd1, char *path, int *end)
{
	char	*abso;

	dup2(f1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	close(end[1]);
	close(f1);
	abso = ft_find_absolute_path(path, cmd1);
	if (!abso)
		exit(127);
	execve(abso, cmd1, NULL);
	perror("execve failed");
	free(abso);
	exit(127);
}

void	second_child_process(int f2, char **cmd2, char *path, int *end)
{
	char	*abso;

	dup2(end[0], STDIN_FILENO);
	dup2(f2, STDOUT_FILENO);
	close(end[1]);
	close(end[0]);
	close(f2);
	abso = ft_find_absolute_path(path, cmd2);
	if (!abso)
		exit(127);
	execve(abso, cmd2, NULL);
	perror("execve failed");
	free(abso);
	exit(127);
}

// void	ft_parent_process(int f2, char **cmd2, char *path, int *end)
// {
// 	pid_t	second_pid;
// 	int		status;

// 	waitpid(pid, &status, 0);
// 	second_pid = fork();
// 	if (second_pid == 0)
// 		second_child_process(f2, cmd2, path, end);
// 	else
// 	{
// 		// je sais pas quoi faire ici ????
// 		close(f2);
// 		close(end[0]);
// 		close(end[1]);
// 	}
// }

// PAS EXECVE DANS UN PARENTS