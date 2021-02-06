/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaran <lkaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:47:10 by lkaran            #+#    #+#             */
/*   Updated: 2020/11/06 15:47:51 by lkaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (dest == NULL || src == NULL)
		return (0);
	while (src[i] != '\0' && i != size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size != 0 && i < size)
	{
		dest[i] = '\0';
	}
	else if (size != 0 && i == size)
	{
		dest[i - 1] = '\0';
	}
	return (ft_strlen(src));
}
