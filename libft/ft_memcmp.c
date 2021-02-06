/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaran <lkaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:46:29 by lkaran            #+#    #+#             */
/*   Updated: 2020/11/06 15:47:51 by lkaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*arr1;
	unsigned char	*arr2;
	int				i;

	arr1 = (unsigned char*)s1;
	arr2 = (unsigned char*)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((arr1[i] == arr2[i]) && (n != 1))
	{
		i++;
		n--;
	}
	return ((unsigned char)arr1[i] - (unsigned char)arr2[i]);
}
