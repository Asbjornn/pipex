/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:41:25 by gcauchy           #+#    #+#             */
/*   Updated: 2025/04/21 12:41:26 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*empty_string(const char *s1, const char *s2)
{
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	return (0);
}

char	*ft_strjoin(char const *s1, const char *s2)
{
	int		i;
	int		j;
	char	*result;

	result = empty_string(s1, s2);
	if (result)
		return (result);
	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		result [i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

// #include <stdio.h>
// int		main(void)
// {
// 	char	mot1[] = "envie de ";
// 	char	mot2[] = "jump ^^";

// 	printf("%s\n", ft_strjoin(mot1, mot2));
// 	return (0);
// }