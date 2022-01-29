/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:37:36 by tdeville          #+#    #+#             */
/*   Updated: 2021/12/16 16:25:11 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	reverse_rotate_a(t_list **tab_a)
{
	t_list	*last;
	t_list	*second_last;

	last = ft_lstlast(*tab_a);
	second_last = ft_lstsecondlast(*tab_a);
	last->next = *tab_a;
	(*tab_a) = last;
	second_last->next = NULL;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_list **tab_b)
{
	t_list	*last;
	t_list	*second_last;

	last = ft_lstlast(*tab_b);
	second_last = ft_lstsecondlast(*tab_b);
	last->next = *tab_b;
	(*tab_b) = last;
	second_last->next = NULL;
	write(1, "rrb\n", 4);
}

void	rra_rrb(t_list **tab_a, t_list **tab_b)
{
	reverse_rotate_a(tab_a);
	reverse_rotate_a(tab_b);
}
