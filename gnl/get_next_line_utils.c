/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaran <lkaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:47:16 by lkaran            #+#    #+#             */
/*   Updated: 2021/01/15 13:48:15 by lkaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2, int length, int i)
{
	int		s1cnt;
	int		s2cnt;
	int		k;
	char	*str;

	s1cnt = (s1) ? ft_strlen(&s1[i]) : 0;
	s2cnt = (s2) ? ft_strlen(s2) : 0;
	length = (length >= 0) ? length : s1cnt + s2cnt;
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (ft_free(0, s1));
	k = 0;
	while (s1 && k < length && k < s1cnt)
		str[k++] = s1[i++];
	i = 0;
	while (s2 && k < length && i < s2cnt)
		str[k++] = s2[i++];
	while (k < length + 1)
		str[k++] = '\0';
	if (s1)
		free(s1);
	return (str);
}
