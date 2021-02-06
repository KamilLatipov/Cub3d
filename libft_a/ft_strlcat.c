/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaran <lkaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:47:06 by lkaran            #+#    #+#             */
/*   Updated: 2020/11/06 15:47:51 by lkaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t destlen;
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (i != size && dest[i] != '\0')
	{
		i++;
	}
	if (i == size)
		return (size + ft_strlen(src));
	else
	{
		destlen = i;
		while (src[j] != '\0' && i < size - 1)
		{
			dest[i] = src[j];
			i++;
			j++;
		}
	}
	dest[i] = '\0';
	return (destlen + ft_strlen(src));
}
