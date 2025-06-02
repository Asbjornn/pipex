/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:41:15 by gcauchy           #+#    #+#             */
/*   Updated: 2025/04/21 12:41:16 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j])
		j++;
	dup = malloc(sizeof(char) * (j + 1));
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// #include <stdio.h>
// int		main(void)
// {
//	const char	mot[] = "MACRON DESTITUTION";
//	constchar	*cpy;
//
//	cpy = ft_strdup(mot);
// 	printf("%d\n", cpy);
//	free(cpy);
// 	return (0);
// }