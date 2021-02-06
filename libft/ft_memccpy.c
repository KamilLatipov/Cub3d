/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaran <lkaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:46:21 by lkaran            #+#    #+#             */
/*   Updated: 2020/11/06 15:47:51 by lkaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*darr;
	unsigned char	*sarr;
	unsigned char	ch;
	size_t			i;

	darr = (unsigned char*)dest;
	sarr = (unsigned char*)src;
	i = 0;
	ch = (unsigned char)c;
	while ((unsigned char)sarr[i] != ch && i != n)
	{
		darr[i] = (unsigned char)sarr[i];
		i++;
	}
	if (i == n)
		return (NULL);
	darr[i] = (unsigned char)sarr[i];
	return ((void *)&dest[i + 1]);
}
