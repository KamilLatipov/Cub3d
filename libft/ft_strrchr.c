/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaran <lkaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:47:25 by lkaran            #+#    #+#             */
/*   Updated: 2020/11/06 15:47:51 by lkaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t slen;

	slen = ft_strlen(s);
	while (slen + 1)
	{
		if (s[slen] == (char)c)
			return ((char *)&s[slen]);
		slen--;
	}
	return (NULL);
}
