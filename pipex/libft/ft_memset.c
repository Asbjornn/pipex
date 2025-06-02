/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:40:37 by gcauchy           #+#    #+#             */
/*   Updated: 2025/04/21 12:40:38 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*mot;

	i = 0;
	mot = (unsigned char *)s;
	while (i < n)
	{
		mot[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// #include <stdio.h>
// int	main(void)
// {
// 	unsigned char s[] = "Bonjour";
// 	int	c = '*';
// 	size_t	n = 8;

// 	printf("Mine : %s\n", (unsigned char *)ft_memset(s, c, n));
// 	printf("True : %s\n", (unsigned char *)memset(s, c, n));
// 	return (0);
// }
