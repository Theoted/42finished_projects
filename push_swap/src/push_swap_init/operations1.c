/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:03:18 by tdeville          #+#    #+#             */
/*   Updated: 2021/12/17 14:31:28 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap_a(t_list *tab_a)
{
	int	*tmp;

	if (tab_a)
	{
		tmp = tab_a->content;
		tab_a->content = tab_a->next->content;
		tab_a->next->content = tmp;
	}
	write(1, "sa\n", 3);
}

void	swap_b(t_list *tab_b)
{
	int	*tmp;

	if (tab_b)
	{
		tmp = tab_b->content;
		tab_b->content = tab_b->next->content;
		tab_b->next->content = tmp;
	}
	write(1, "sb\n", 3);
}

void	sa_sb(t_list *tab_a, t_list *tab_b)
{
	swap_a(tab_a);
	swap_b(tab_b);
}

void	push_a(t_list **tab_a, t_list **tab_b)
{
	t_list	*tmp;

	if (*tab_b)
	{	
		tmp = *tab_b;
		*tab_b = (*tab_b)->next;
		ft_lstadd_front(tab_a, tmp);
		write(1, "pa\n", 3);
	}
}

void	push_b(t_list **tab_b, t_list **tab_a)
{
	t_list	*tmp;

	if (*tab_a)
	{	
		tmp = *tab_a;
		*tab_a = (*tab_a)->next;
		ft_lstadd_front(tab_b, tmp);
		write(1, "pb\n", 3);
	}
}
