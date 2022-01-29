/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:47:17 by tdeville          #+#    #+#             */
/*   Updated: 2022/01/19 09:53:14 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	find_closest(t_list *tab, int min, int max)
{
	int	i;
	int	j;
	int	*index;
	int	len;

	i = 0;
	j = 0;
	index = ft_calloc(ft_lstsize(tab) + 1, sizeof(int));
	len = ft_lstsize(tab);
	while (tab)
	{
		if (*(int *)tab->content >= min && *(int *)tab->content <= max)
			index[j] = 1;
		j++;
		tab = tab->next;
	}
	while (len && index[len] == 0)
	{
		len--;
		i++;
	}
	free(index);
	return (i);
}

long	l_atoi(const char *str)
{
	long	res;
	long	neg;
	long	i;

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
	}
	return (res * neg);
}

int	write_error(char **s)
{
	write(2, "Error\n", 6);
	free_all(s);
	return (1);
}
