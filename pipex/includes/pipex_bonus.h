/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:58:41 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/10 15:19:33 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>

/*  ~~~~~~~~~~~~~~~~~~~~~~~~~~ PATH FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~  */

char	*ft_get_path(char *envp[]);
char	*ft_find_absolute_path(char *path, char **cmd);

/*  ~~~~~~~~~~~~~~~~~~~~~~~~~~ EXECUTE FUNCTION ~~~~~~~~~~~~~~~~~~~~~~~~~~  */

void	exec_cmd(char *command, char *envp[]);

/*  ~~~~~~~~~~~~~~~~~~~~~~~~~~ UTILS FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~  */

void	free_tab(char **tab);
void	warning_format(void);

#endif