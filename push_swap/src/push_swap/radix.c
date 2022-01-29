/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:12:34 by tdeville          #+#    #+#             */
/*   Updated: 2022/01/17 13:59:45 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_radix(t_list **tab_a, t_list **tab_b)
{
	int	i;
	int	bit;
	int	len;

	i = 0;
	bit = 0;
	while (check_sort(*tab_a))
	{
		len = ft_lstsize(*tab_a);
		while (i < len)
		{
			if (!(*(int *)(*tab_a)->content >> bit & 1))
				push_b(tab_b, tab_a);
			else
				rotate_a(tab_a);
			i++;
		}
		i = -1;
		len = ft_lstsize(*tab_b);
		while (++i < len)
			push_a(tab_a, tab_b);
		bit++;
		i = 0;
	}
}
