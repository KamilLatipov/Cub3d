/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaran <lkaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:46:37 by lkaran            #+#    #+#             */
/*   Updated: 2020/11/06 15:47:51 by lkaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *darr;
	unsigned char *sarr;

	darr = (unsigned char*)dest;
	sarr = (unsigned char*)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (!n)
		return ((void *)dest);
	if (sarr <= darr)
	{
		n--;
		while (n != 0)
		{
			darr[n] = sarr[n];
			n--;
		}
		darr[n] = sarr[n];
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return ((void *)dest);
}
