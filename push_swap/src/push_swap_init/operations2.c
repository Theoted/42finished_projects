/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:11:24 by tdeville          #+#    #+#             */
/*   Updated: 2021/12/27 11:50:59 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate_a(t_list **tab_a)
{
	t_list	*last;
	t_list	*head;

	if (*tab_a)
	{
		last = ft_lstlast(*tab_a);
		head = (*tab_a);
		last->next = head;
		(*tab_a) = (*tab_a)->next;
		last->next->next = NULL;
		write(1, "ra\n", 3);
	}
}

void	rotate_b(t_list **tab_b)
{
	t_list	*last;
	t_list	*head;

	if (*tab_b)
	{
		last = ft_lstlast(*tab_b);
		head = (*tab_b);
		last->next = head;
		(*tab_b) = (*tab_b)->next;
		last->next->next = NULL;
		write(1, "rb\n", 3);
	}
}

void	ra_rb(t_list **tab_a, t_list **tab_b)
{
	rotate_a(tab_a);
	rotate_a(tab_b);
}
