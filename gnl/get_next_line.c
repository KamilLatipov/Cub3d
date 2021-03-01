/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaran <lkaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:47:26 by lkaran            #+#    #+#             */
/*   Updated: 2021/01/15 13:48:15 by lkaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *remainder)
{
	if (buffer)
		free(buffer);
	if (remainder)
		free(remainder);
	return (NULL);
}

char	*ft_get_line(int fd, char **line, char *remainder, int *ret)
{
	char	*buffer;
	int		i;

	*ret = 1;
	i = 0;
	if ((buffer = (char *)malloc(sizeof(char) * (4096+ 1))) == NULL)
		return (ft_free(0, remainder));
	while (remainder[i] != '\n' && *ret != 0)
	{
		if ((*ret = read(fd, buffer, 4096)) < 0)
			return (ft_free(buffer, remainder));
		buffer[*ret] = '\0';
		if ((remainder = ft_strjoin_gnl(remainder, buffer, -1, 0)) == NULL)
			return (ft_free(buffer, 0));
		while (remainder[i] != '\n' && remainder[i] != '\0')
			i++;
	}
	free(buffer);
	*ret = (*ret == 0 && (remainder[i] != '\n')) ? 0 : 1;
	if ((*line = ft_strjoin_gnl(0, remainder, i, 0)) == NULL)
		return (ft_free(0, remainder));
	i = (remainder[i] == '\n') ? i : i - 1;
	return (ft_strjoin_gnl(remainder, 0, -1, i + 1));
}

int		get_next_line(int fd, char **line)
{
	static char	*remainder;
	int			ret;

	ret = 1;
	if (fd < 0 || line == NULL)
		return (-1);
    *line = NULL;
	if (remainder == NULL)
	{
		if ((remainder = ft_strjoin_gnl(0, 0, -1, 0)) == NULL)
			return (-1);
	}
	if ((remainder = ft_get_line(fd, line, remainder, &ret)) == NULL)
		return (-1);
	if (ret == 0)
	{
		free(remainder);
		remainder = NULL;
	}
	return (ret);
}
