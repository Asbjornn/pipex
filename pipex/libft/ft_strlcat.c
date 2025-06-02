/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:41:30 by gcauchy           #+#    #+#             */
/*   Updated: 2025/04/21 12:41:31 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lendst;
	size_t	lensrc;
	size_t	i;
	size_t	j;

	lensrc = ft_strlen(src);
	lendst = ft_strlen(dst);
	if (!dst && size == 0)
		return (lensrc);
	if (size < lendst)
		return (lensrc + size);
	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	while (src[j] && ((i + j) < (size - 1) && size != 0))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (lendst + lensrc);
}

// #include <stdio.h>
// #include <string.h>

// // Déclaration de ta fonction
// size_t	ft_strlcat(char *dst, const char *src, size_t size);

// int main(void)
// {
//     char buffer1[20] = "Hello";
//     char buffer2[10] = "Hello";
//     char buffer3[6] = "Hi";
//     char buffer4[10] = "";
//     char buffer5[10] = "Salut";
//     size_t ret;

//     // Cas 1 : buffer assez grand
//     ret = ft_strlcat(buffer1, " World", sizeof(buffer1));
//     printf("Cas 1 : %s | Retour : %zu\n", buffer1, ret);

//     // Cas 2 : buffer trop petit
//     ret = ft_strlcat(buffer2, " World", sizeof(buffer2));
//     printf("Cas 2 : %s | Retour : %zu\n", buffer2, ret);

//     // Cas 3 : buffer pile la place pour le \0
//     ret = ft_strlcat(buffer3, "123456", sizeof(buffer3));
//     printf("Cas 3 : %s | Retour : %zu\n", buffer3, ret);

//     // Cas 4 : buffer vide
//     ret = ft_strlcat(buffer4, "Test", sizeof(buffer4));
//     printf("Cas 4 : %s | Retour : %zu\n", buffer4, ret);

//     // Cas 5 : size = 0
//     ret = ft_strlcat(buffer5, "Test", 0);
//     printf("Cas 5 : %s | Retour : %zu\n", buffer5, ret);

//     return 0;
// }
