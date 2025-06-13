/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:04:56 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/11 12:05:13 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

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
