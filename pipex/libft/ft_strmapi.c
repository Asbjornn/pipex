/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:41:48 by gcauchy           #+#    #+#             */
/*   Updated: 2025/04/21 12:41:49 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*mot;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	mot = malloc(sizeof(char) * (i + 1));
	if (!mot)
		return (NULL);
	i = 0;
	while (s[i])
	{
		mot[i] = f(i, s[i]);
		i++;
	}
	mot[i] = '\0';
	return (mot);
}
