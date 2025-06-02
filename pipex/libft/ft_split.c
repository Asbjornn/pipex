/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:22:20 by gcauchy           #+#    #+#             */
/*   Updated: 2025/04/21 13:22:21 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_range(char **tab, int h)
{
	int	i;

	i = 0;
	while (i < h)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	*copy(char const *s, char c, char *tab, int i)
{
	int	j;

	j = 0;
	while (s[i] != c && s[i])
	{
		tab[j] = s[i];
		i++;
		j++;
	}
	tab[j] = '\0';
	return (tab);
}

static char	**get_memory(char const *s, char c, char **tab)
{
	int	i[3];

	i[0] = 0;
	i[1] = 0;
	while (s[i[0]])
	{
		i[2] = 0;
		if (s[i[0]] == c)
			i[0]++;
		else
		{
			while (s[i[0] + i[2]] != c && s[i[0] + i[2]])
				i[2]++;
			tab[i[1]] = malloc(sizeof(char) * (i[2] + 1));
			if (!tab[i[1]])
			{
				free_range(tab, i[1]);
				return (NULL);
			}
			copy(s, c, tab[i[1]], i[0]);
			i[0] += i[2];
			i[1]++;
		}
	}
	return (tab);
}

int	get_word(char const *s, char c)
{
	int		i;
	int		mot;

	i = 0;
	mot = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			mot++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (mot);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		mot;

	mot = 0;
	if (!s)
		return (NULL);
	mot = get_word(s, c);
	tab = (char **)malloc(sizeof(char *) * (mot + 1));
	if (!tab)
		return (NULL);
	if (!get_memory(s, c, tab))
		return (NULL);
	tab[mot] = 0;
	return (tab);
}

// #include <stdio.h>
// int	main(int argc, char *argv[])
// {
// 	int		i;
// 	char	**tabb;

// 	i = 0;
// 	tabb = ft_split("bonjour je suis gabin t mamamam", argv[argc - 1]);
// 	while (tabb && tabb[i])
// 	{
// 		printf("mot n.%d : %s\n", i, tabb[i]);
// 		i++;
// 	}
// 	return (0);
// }