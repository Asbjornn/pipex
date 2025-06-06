/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:01:36 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/06 13:48:42 by gcauchy          ###   ########.fr       */
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

/*  ========================== CHILD FUNCTIONS ============================  */

void	first_child_process(char *argv[], int *end, char *envp[]);
void	second_child_process(char *argv[], int *end, char *envp[]);

/*  ========================== PATH FUNCTIONS ============================  */

char	*ft_get_path(char *envp[]);
char	*ft_find_absolute_path(char *path, char **cmd);

/*  ========================== UTILS FUNCTION ============================  */

void	free_tab(char **tab);

#endif