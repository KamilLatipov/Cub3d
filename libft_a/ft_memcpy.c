/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaran <lkaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:46:33 by lkaran            #+#    #+#             */
/*   Updated: 2020/11/06 15:47:51 by lkaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*darr;
	unsigned char	*sarr;
	size_t			i;

	if (n == 0)
		return (dest);
	if (dest == NULL && src == NULL)
		return (NULL);
	darr = (unsigned char *)dest;
	sarr = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		darr[i] = (unsigned char)sarr[i];
		i++;
	}
	return ((void *)dest);
}
