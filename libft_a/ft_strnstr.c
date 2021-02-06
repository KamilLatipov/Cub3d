/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaran <lkaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:47:21 by lkaran            #+#    #+#             */
/*   Updated: 2020/11/06 15:47:51 by lkaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t s2count;
	size_t s1count;

	s2count = 0;
	s1count = 0;
	if (s2[s2count] == '\0')
		return ((char *)s1);
	while (n != 0 && s1[s1count] != '\0')
	{
		if (s2[s2count] == s1[s1count])
			s2count++;
		else
		{
			s1count -= s2count;
			n += s2count;
			s2count = 0;
		}
		s1count++;
		n--;
		if (s2[s2count] == '\0')
			return ((char *)&s1[s1count - s2count]);
	}
	return (NULL);
}
