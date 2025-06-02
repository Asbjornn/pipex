/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:41:11 by gcauchy           #+#    #+#             */
/*   Updated: 2025/04/21 12:41:11 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned char	c_bis;

	i = 0;
	c_bis = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c_bis == 0)
		return ((char *)&s[i]);
	return (NULL);
}

// #include <stdio.h>
// int		main(void)
// {
// 	const char s[] = "teste";
// 	unsigned int	c = 1024;

// 	printf("Mine : %s\n", ft_strchr(s, c));
// 	printf("True : %s\n", strchr(s, c));
// }
