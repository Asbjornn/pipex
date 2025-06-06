/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:18:06 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/05 17:25:41 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char const *s, char c);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, const char *s2);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);


#endif