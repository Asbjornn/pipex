/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 09:32:13 by gcauchy           #+#    #+#             */
/*   Updated: 2025/05/30 17:09:30 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_child_process(int f1, char ** cmd1, char **env, int *end)
{
	dup2(end[1], STDOUT_FILENO);
	dup2(f1, STDIN_FILENO);
	close(end[0]);
	execv(*env, cmd1);
}

void	ft_parent_process(int f2, char ** cmd2, char **env, int *end)
{
	// waitpid();
	dup2(end[0], STDIN_FILENO);
	dup2(f2, STDOUT_FILENO);
	close(end[1]);
	execv(*env, cmd2);
}
