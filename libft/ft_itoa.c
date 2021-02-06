/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaran <lkaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 09:45:02 by lkaran            #+#    #+#             */
/*   Updated: 2020/11/13 09:45:06 by lkaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fill_str(char *str, size_t size, int isneg, int n)
{
	while (size--)
	{
		str[size + isneg] = n % 10 + '0';
		n /= 10;
	}
}

char		*ft_itoa(int n)
{
	char	*str;
	size_t	size;
	int		num;
	int		isneg;

	isneg = 0;
	size = 1;
	num = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		isneg = 1;
	while (num /= 10)
		size++;
	if ((str = (char *)malloc(sizeof(char) * (size + 1 + isneg))) == NULL)
		return (NULL);
	str[size + isneg] = '\0';
	if (isneg)
	{
		str[0] = '-';
		n *= -1;
	}
	ft_fill_str(str, size, isneg, n);
	return (str);
}
