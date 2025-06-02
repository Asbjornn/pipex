/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:38:19 by gcauchy           #+#    #+#             */
/*   Updated: 2025/04/21 12:38:21 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && 127 >= c)
		return (1);
	return (0);
}

// #include <stdio.h>
// int		main(void)
// {
// 	printf("%d\n", ft_isascii('W'));
// 	return (0);
// }