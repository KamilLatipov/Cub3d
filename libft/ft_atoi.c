/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaran <lkaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:40:07 by lkaran            #+#    #+#             */
/*   Updated: 2020/11/06 15:41:22 by lkaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t	count;
	int		neg;
	int		retval;

	count = 0;
	neg = 1;
	retval = 0;
	while (str[count] == ' ' || (str[count] >= 8 && str[count] <= 13))
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			neg *= -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		retval *= 10;
		retval += str[count] - 48;
		count++;
	}
	return (retval * neg);
}
