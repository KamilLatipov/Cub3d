/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaran <lkaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:49:48 by lkaran            #+#    #+#             */
/*   Updated: 2021/01/15 13:49:50 by lkaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_GET_NEXT_LINE_H
# define GNL_GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
int		ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2, int length, int i);
char	*ft_get_line(int fd, char **line, char *remainder, int *ret);
char	*ft_free(char *buffer, char *remainder);

#endif
