/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:38:46 by tdeville          #+#    #+#             */
/*   Updated: 2022/01/12 09:49:09 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	little_sort(t_list **tab)
{
	if (*(int *)(*tab)->content == 3
		&& *(int *)(*tab)->next->content == 1)
		rotate_a(tab);
	else if (*(int *)(*tab)->content == 1
		&& *(int *)(*tab)->next->content == 3)
	{
		swap_a(*tab);
		rotate_a(tab);
	}
	else if (*(int *)(*tab)->content == 3
		&& *(int *)(*tab)->next->content == 2)
	{
		swap_a(*tab);
		reverse_rotate_a(tab);
	}
	else if (*(int *)(*tab)->content == 2
		&& *(int *)(*tab)->next->content == 1)
		swap_a(*tab);
	else if (*(int *)(*tab)->content == 2
		&& *(int *)(*tab)->next->content == 3)
		reverse_rotate_a(tab);
}

void	medium_sort(t_list **tab_a, t_list **tab_b)
{
	int	check;
	int	i;

	check = 0;
	i = 1;
	while (check < 2 && ft_lstsize(*tab_a))
	{
		if ((*(int *)(*tab_a)->content) == 4
			|| (*(int *)(*tab_a)->content) == 5)
		{
			push_b(tab_b, tab_a);
			check++;
		}
		else
			rotate_a(tab_a);
	}
	little_sort(tab_a);
	if ((*(int *)(*tab_b)->content) < (*(int *)(*tab_b)->next->content))
		swap_b(*tab_b);
	while (ft_lstsize(*tab_b))
		push_a(tab_a, tab_b);
	rotate_a(tab_a);
	rotate_a(tab_a);
}

void	big_sort_push_b(t_list **tab_a, t_list **tab_b, int min, int *check)
{
	if (*(int *)(*tab_a)->content >= min
		&& *(int *)(*tab_a)->content <= (min + 12))
	{
		push_b(tab_b, tab_a);
		(*check)++;
	}
	else if (*(int *)(*tab_a)->content >= (min + 12)
		&& *(int *)(*tab_a)->content <= ((min + 12) + 12))
	{
		push_b(tab_b, tab_a);
		if (ft_lstsize(*tab_b) > 1)
			rotate_b(tab_b);
		(*check)++;
	}
	else
	{
		if (find_closest(*tab_a, min, (min + 12 + 12))
			< find_index(*tab_a, min, (min + 12 + 12)))
			reverse_rotate_a(tab_a);
		else
			rotate_a(tab_a);
	}
}

void	big_sort_push_a(t_list **tab_a, t_list **tab_b)
{
	int	max;
	int	len;

	while (ft_lstsize(*tab_b))
	{
		len = ft_lstsize(*tab_b);
		max = len;
		if (*(int *)(*tab_b)->content == max)
			push_a(tab_a, tab_b);
		else
		{
			while (*(int *)(*tab_b)->content != max)
			{
				if (find_closest(*tab_b, max, (max))
					< find_index(*tab_b, max, (max)))
					reverse_rotate_b(tab_b);
				else
					rotate_b(tab_b);
			}
			push_a(tab_a, tab_b);
		}
		max--;
	}
}

void	big_sort(t_list **tab_a, t_list **tab_b)
{
	int	min;
	int	check;

	min = 0;
	check = 0;
	while (ft_lstsize(*tab_a))
	{
		while (check < (12 * 2) && ft_lstsize(*tab_a))
			big_sort_push_b(tab_a, tab_b, min, &check);
		check = 0;
		min += 12 * 2;
	}
	big_sort_push_a(tab_a, tab_b);
}
