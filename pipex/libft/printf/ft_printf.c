/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:02:06 by gcauchy           #+#    #+#             */
/*   Updated: 2025/04/23 13:40:08 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_type(char c, va_list arg)
{
	int	value;

	value = 0;
	if (c == 'd' || c == 'i')
		value += ft_print_int(va_arg(arg, int));
	else if (c == 'u')
		value += ft_print_u_int(va_arg(arg, unsigned int));
	else if (c == 's')
		value += ft_print_string(va_arg(arg, char *));
	else if (c == 'c')
		value += ft_print_char(va_arg(arg, int));
	else if (c == 'p')
		value += ft_print_address(va_arg(arg, void *));
	else if (c == 'x' || c == 'X')
		value += ft_print_hexa(va_arg(arg, int), c);
	else if (c == '%')
		value += ft_print_char('%');
	return (value);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!s)
		return (-1);
	va_start(args, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			count += get_type(s[i], args);
		}
		else
		{
			count += ft_print_char(s[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}

// #include <stdio.h>
// int	main(void)
// {
//void	*ptr;
//int		i;

//i = 0;
//ptr = &i;
// 	ft_printf(" NULL %s NULL ", NULL);
// 	ft_printf("Les test\n");
// 	ft_printf("%d\n", 578);
// 	ft_printf("int avec i -> %i\n", 682);
// 	ft_printf("string -> %s\n", "Je suis un string");
// 	ft_printf("char -> %c\n", 'c');
// 	ft_printf("pourentage -> %%\n", 'c');
// 	ft_printf("%c", '0');
// 	ft_printf("base 16 minuscule -> %x\n", -1);
// 	ft_printf("base 16 majuscule -> %X\n", 16);
// 	ft_printf("pointeur ->     %p\n", 0);
// 	ft_printf("test RAAMY -> %d,\n%s\n", 23, "Bonjour");
// 	printf("real function : %x\n", -1);
// 	return (0);
// }
