/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:41:56 by gcauchy           #+#    #+#             */
/*   Updated: 2025/04/21 12:41:58 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!little[0])
		return ((char *)big);
	while (big[i] && (i < len))
	{
		while ((big[i + j] == little[j] && little [j]) && ((i + j) < len))
			j++;
		if (!little[j])
			return ((char *)&big[i]);
		j = 0;
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// char	*ft_strnstr(const char *big, const char *little, size_t len);

// int main(void)
// {
//     const char *text = "Salut les amis";
//     const char *to_find = "les";
//     char *res = ft_strnstr(text, to_find, 12);

//     if (res)
//         printf("Trouvé : '%s'\n", res);
//     else
//         printf("Non trouvé\n");

//     return 0;
// }
