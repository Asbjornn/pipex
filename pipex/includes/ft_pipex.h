/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:01:36 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/05 09:38:15 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>

void	first_child_process(int f1, char **cmd1, char *path, int *end);
void	second_child_process(int f2, char **cmd2, char *path, int *end);

char	*ft_get_path(char *envp[]);
char	*ft_find_absolute_path(char *path, char **cmd);

void	free_tab(char **tab);
void	cleanup(char **s1, char **s2);
#endif