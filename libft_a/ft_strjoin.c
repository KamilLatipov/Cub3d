/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaran <lkaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 10:07:57 by lkaran            #+#    #+#             */
/*   Updated: 2020/11/09 10:08:28 by lkaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1cnt;
	size_t	s2cnt;
	size_t	i;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	s1cnt = 0;
	while (s1[s1cnt] != '\0')
	{
		str[i++] = s1[s1cnt++];
	}
	s2cnt = 0;
	while (s2[s2cnt] != '\0')
	{
		str[i++] = s2[s2cnt++];
	}
	str[i] = '\0';
	return (str);
}
