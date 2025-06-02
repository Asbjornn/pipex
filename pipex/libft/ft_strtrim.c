/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:42:06 by gcauchy           #+#    #+#             */
/*   Updated: 2025/04/21 12:42:07 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		start;
	int		end;
	int		len;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_is_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_is_in_set(s1[end - 1], set))
		end--;
	len = end - start;
	trim = malloc(sizeof(char) * (len + 1));
	if (!trim)
		return (NULL);
	i = -1;
	while (++i < len)
		trim[i] = s1[start + i];
	trim[i] = '\0';
	return (trim);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char const s1[] = "   tes te   ";
// 	char const set[] = " ";

// 	printf("%s\n", ft_strtrim(s1, set));
// }
