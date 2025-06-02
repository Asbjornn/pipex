/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:01:56 by gcauchy           #+#    #+#             */
/*   Updated: 2025/04/23 11:02:00 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_write_hexa(int i, char c)
{
	char	letter;

	if (i < 10)
	{
		letter = i + '0';
		write(1, &letter, 1);
	}
	else
	{
		if (c == 'x')
			letter = (i + 'a') - 10;
		else if (c == 'X')
			letter = (i + 'A') - 10;
		write(1, &letter, 1);
	}
}

int	ft_print_hexa_add(unsigned long i, char c)
{
	unsigned long	temp[16];
	unsigned long	count;
	int				result;

	count = 0;
	if (!i)
		return (ft_print_char('0'));
	while (i > 0)
	{
		temp[count] = i % 16;
		i /= 16;
		count++;
	}
	result = count;
	while (count-- > 0)
		ft_write_hexa(temp[count], c);
	return (result);
}

int	ft_print_address(void *ptr)
{
	unsigned long	addr;
	int				result;

	if (!ptr)
		return (ft_print_string("(nil)"));
	result = 0;
	addr = (unsigned long)ptr;
	result += ft_print_string("0x");
	return (result += ft_print_hexa_add(addr, 'x'));
}
