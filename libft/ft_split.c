/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaran <lkaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 10:04:54 by lkaran            #+#    #+#             */
/*   Updated: 2020/11/13 12:57:58 by lkaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_str(char const *s, char c)
{
	size_t i;
	size_t strcnt;

	i = 0;
	strcnt = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
		{
			strcnt++;
		}
		i++;
	}
	return (strcnt);
}

static size_t	ft_count_char(char const *s, size_t i, char c)
{
	size_t j;

	j = 0;
	while (s[i] != c && s[i] != '\0')
	{
		j++;
		i++;
	}
	return (j);
}

static void		*ft_free(char **arr, size_t j)
{
	while (j != 0)
	{
		free(arr[j]);
		j--;
	}
	free(arr[0]);
	free(arr);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	strnum;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (0);
	strnum = ft_count_str(s, c);
	if ((arr = (char **)malloc(sizeof(char *) * (strnum + 1))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (strnum)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if ((arr[j] = ft_substr(s, i, ft_count_char(s, i, c))) == NULL)
			return (ft_free(arr, j));
		i = i + ft_count_char(s, i, c);
		j++;
		strnum--;
	}
	arr[j] = NULL;
	return (arr);
}
