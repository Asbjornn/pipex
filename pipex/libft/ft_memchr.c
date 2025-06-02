/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:40:07 by gcauchy           #+#    #+#             */
/*   Updated: 2025/04/21 12:40:09 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*mot;
	unsigned char	cc;

	i = 0;
	cc = c;
	mot = (unsigned char *)s;
	while (i < n)
	{
		if (mot[i] == cc)
			return ((void *)mot + i);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char	mot1[] = "Grenouille je zonjour";

// 	printf("my function     : %p\n", ft_memchr(mot1,'j', 18));
// 	printf("real function   : %p\n", memchr(mot1, 'j', 18));
// 	return (0);
// }
