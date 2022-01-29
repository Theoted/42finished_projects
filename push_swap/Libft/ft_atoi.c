/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:51:05 by tdeville          #+#    #+#             */
/*   Updated: 2021/12/27 11:08:27 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sign(int sign)
{
	if (sign < 0)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		res;
	int		neg;
	int		i;

	res = 0;
	neg = 1;
	i = -1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - 48);
		i++;
		if ((long int)res > 2147483647)
			return (check_sign(neg));
	}
	return (res * neg);
}
