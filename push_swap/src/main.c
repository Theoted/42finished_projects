/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:03:23 by tdeville          #+#    #+#             */
/*   Updated: 2022/01/17 14:00:23 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_sort(t_list *tab_a)
{
	if (tab_a)
	{
		while (tab_a)
		{
			if ((tab_a->next)
				&& (*(int *)tab_a->next->content < *(int *)tab_a->content))
				return (1);
			tab_a = tab_a->next;
		}
	}
	return (0);
}

void	clear_lists(t_list **tab_a, t_list **tab_b)
{
	ft_lstclear(tab_a, del);
	ft_lstclear(tab_b, del);
}

int	main(int ac, char **av)
{
	t_list	*tab_a;
	t_list	*tab_b;

	tab_a = NULL;
	tab_b = NULL;
	if (ac < 2 || error(ac, av))
		return (0);
	tab_a = create_list(ac, av);
	if (tab_a && !check_sort(tab_a))
		clear_lists(&tab_a, &tab_b);
	if (ft_lstsize(tab_a) == 100)
		big_sort(&tab_a, &tab_b);
	else if (ft_lstsize(tab_a) == 500)
		ft_radix(&tab_a, &tab_b);
	else if (ft_lstsize(tab_a) == 3)
		little_sort(&tab_a);
	else if (ft_lstsize(tab_a) == 5)
		medium_sort(&tab_a, &tab_b);
	else
		ft_radix(&tab_a, &tab_b);
	clear_lists(&tab_a, &tab_b);
	return (0);
}
