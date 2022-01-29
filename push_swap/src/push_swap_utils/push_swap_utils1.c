/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:41:32 by tdeville          #+#    #+#             */
/*   Updated: 2021/12/16 17:49:10 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_list	*ft_lstsecondlast(t_list *lst)
{
	if (lst)
	{
		while (lst)
		{
			if (lst->next->next == NULL)
				return (lst);
			lst = lst->next;
		}
	}
	return (0);
}

void	free_all(char **num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		free(num[i]);
		i++;
	}
	free(num);
}

void	del(void *content)
{
	content = NULL;
}

int	*indexing_tab(int *tab, int ac, char **av)
{
	int	size;
	int	i;
	int	j;
	int	bigger;
	int	*indexing_tab;

	size = int_tab_size(ac, av);
	i = -1;
	j = -1;
	bigger = 0;
	indexing_tab = malloc(sizeof(int) * size);
	while (++i < size)
	{
		while (++j < size)
		{
			if (tab[j] > tab[i])
				bigger++;
		}
		indexing_tab[i] = size - bigger;
		j = -1;
		bigger = 0;
	}
	free(tab);
	return (indexing_tab);
}

int	find_index(t_list *tab, int min, int max)
{
	int	i;

	i = 0;
	while (tab)
	{
		if (*(int *)(tab)->content >= min
			&& *(int *)(tab)->content <= max)
			return (i + 1);
		tab = tab->next;
		i++;
	}
	return (0);
}
