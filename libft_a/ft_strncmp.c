/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaran <lkaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:47:17 by lkaran            #+#    #+#             */
/*   Updated: 2020/11/06 15:47:51 by lkaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t cnt;

	cnt = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s1[cnt] == s2[cnt] && s1[cnt] != '\0' && s2[cnt] != '\0' && n)
	{
		cnt++;
		n--;
	}
	if (n == 0)
		cnt--;
	return ((unsigned char)s1[cnt] - (unsigned char)s2[cnt]);
}
