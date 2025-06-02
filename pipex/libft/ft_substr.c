/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:42:11 by gcauchy           #+#    #+#             */
/*   Updated: 2025/04/21 12:42:11 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	d;
	char	*str;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	d = 0;
	while (s[start + d] && d < len)
	{
		str[d] = s[start + d];
		d++;
	}
	str[d] = '\0';
	return (str);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char const s[] = "hola";
// 	unsigned int start;
// 	size_t	len;

// 	start = 46486848;
// 	len = 0;

// 	printf("%s\n", ft_substr(s, start, len));
// }
