/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaran <lkaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 10:04:39 by lkaran            #+#    #+#             */
/*   Updated: 2020/11/09 10:08:28 by lkaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char const *s1, char const *set, size_t i)
{
	size_t j;

	j = 0;
	while (set[j] != '\0')
	{
		if (s1[i] == set[j])
			return (1);
		j++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	startpos;
	size_t	endpos;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	startpos = 0;
	while (startpos < ft_strlen(s1) && ft_is_set(s1, set, startpos))
	{
		startpos++;
	}
	endpos = ft_strlen(s1);
	while (endpos > 0 && ft_is_set(s1, set, endpos - 1))
	{
		endpos--;
	}
	if (!(endpos))
		return (ft_substr(s1, startpos, 0));
	str = ft_substr(s1, startpos, endpos - startpos);
	return (str);
}
