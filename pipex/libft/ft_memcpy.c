/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:40:20 by gcauchy           #+#    #+#             */
/*   Updated: 2025/04/21 12:40:22 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy( void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*sorc;
	unsigned char	*dst;

	if (!dest && !src)
		return (NULL);
	sorc = (unsigned char *)src;
	dst = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		dst[i] = sorc[i];
		i++;
	}
	return ((void *)dest);
}

// #include <stdio.h>
// int	main(void)
// {
// 	size_t	n = 3;
// 	unsigned char s[] = "0";
// 	unsigned char d[] = "abc";

// 	printf("Mine : %s\n", (unsigned char *)ft_memcpy((void *)d, s, n));
// 	printf("True : %s\n", (unsigned char *)memcpy((void *)d, s, n));

// 	printf("%p\n", ft_memcpy(((void*)0), ((void*)0), 3));
// 	printf("%p\n", memcpy(((void*)0), ((void*)0), 3));
// }
