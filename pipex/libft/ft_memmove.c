/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:40:30 by gcauchy           #+#    #+#             */
/*   Updated: 2025/04/21 12:40:33 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*str;

	if (!dest && !src)
		return (NULL);
	i = -1;
	dst = (unsigned char *)dest;
	str = (unsigned char *)src;
	if (str > dst)
	{
		while (++i < len)
			dst[i] = str[i];
	}
	else
	{
		while (len-- > 0)
			dst[len] = str[len];
	}
	return (dst);
}

// #include <stdio.h>
// int main(void)
// {
// 	char	src1[] = "Hello, World!";
// 	char	dst1[50];
// 	printf("Avant ft_memmove (cas non-chevauchant):\n");
// 	printf("src1: %s\n", src1);
// 	printf("dst1: %s\n", dst1);
// 	ft_memmove(dst1, src1, 13);
// 	printf("\nAprès ft_memmove (cas non-chevauchant):\n");
// 	printf("src1: %s\n", src1);
// 	printf("dst1: %s\n", dst1);
// 	char	src2[] = "Hello, World!";
// 	printf("\nAvant ft_memmove (cas chevauchant):\n");
// 	printf("src2: %s\n", src2);
// 	ft_memmove(src2 + 7, src2, 6);
// 	printf("\nAprès ft_memmove (cas chevauchant):\n");
// 	printf("src2: %s\n", src2);
// 	char	src3[] = "Hello, World!";
// 	printf("\n\n\n %s", (char *)ft_memmove(src3 + 7, src3, 13));
// 	return (0);
// }
