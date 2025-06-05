/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:36:19 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/05 15:37:04 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

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

/*
PATH=

cmd = 	ls 
		-l
path =/home/gcauchy/bin/ls

char *all_cmd;

all_cmd = ft_strjoin(path, '/');
all_cmd = ft_strjoin(all_cmd, cmd[0]);
*/