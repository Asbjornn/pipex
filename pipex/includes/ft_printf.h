/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:18:06 by gcauchy           #+#    #+#             */
/*   Updated: 2025/04/23 13:18:08 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
int		ft_print_address(void *ptr);
int		ft_print_char(char c);
int		ft_print_hexa(int i, char c);
int		ft_print_int(int i);
int		ft_print_u_int(unsigned int i);
int		ft_print_string(char *str);
int		ft_printf(const char *s, ...);

#endif
