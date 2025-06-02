/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:53:29 by gcauchy           #+#    #+#             */
/*   Updated: 2025/04/21 12:26:20 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mot;
	size_t	total;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (nmemb > (SIZE_MAX / size) && size != 0)
		return (NULL);
	total = (nmemb * size);
	mot = (char *)malloc(total);
	if (!mot)
		return (NULL);
	ft_memset(mot, 0, total);
	return (mot);
}
