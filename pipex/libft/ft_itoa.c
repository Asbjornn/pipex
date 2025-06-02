/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:45:50 by gcauchy           #+#    #+#             */
/*   Updated: 2025/04/21 12:38:57 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	id;

	id = 0;
	while (src[id] != '\0')
	{
		dest[id] = src[id];
		id++;
	}
	dest[id] = '\0';
	return (dest);
}

static int	get_size(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static char	*copy(char *word, int n, int size, int o)
{
	int	i;
	int	n_copy;

	while (size > 0)
	{
		n_copy = n;
		i = 0;
		while (i < size - 1)
		{
			n_copy /= 10;
			i++;
		}
		n_copy %= 10;
		word[o] = (n_copy + '0');
		o++;
		size--;
	}
	word[o] = '\0';
	return (word);
}

static char	*get_memory(int n, char *word, int size)
{
	int		o;

	o = 0;
	if (n < 0)
	{
		word = (char *)malloc(sizeof(char) * (size + 2));
		if (!word)
			return (NULL);
		word[0] = '-';
		n *= -1;
		o = 1;
	}
	else
	{
		word = (char *)malloc(sizeof(char) * (size + 1));
		if (!word)
			return (NULL);
		o = 0;
	}
	return (copy(word, n, size, o));
}

char	*ft_itoa(int n)
{
	char	*word;
	int		size;

	if (n == -2147483648)
	{
		word = (char *)malloc(sizeof(char) * 12);
		if (!word)
			return (NULL);
		ft_strcpy(word, "-2147483648");
		return (word);
	}
	if (n == 0)
	{
		word = (char *)malloc(sizeof(char) * 2);
		if (!word)
			return (NULL);
		ft_strcpy(word, "0");
		return (word);
	}
	word = NULL;
	size = get_size(n);
	return (get_memory(n, word, size));
}

// #include <stdio.h>
// int		main(void)
// {
// 		printf("%s\n", ft_itoa(1654));
// 		return (0);
// }