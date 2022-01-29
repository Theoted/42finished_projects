/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:18:36 by tdeville          #+#    #+#             */
/*   Updated: 2022/01/27 09:41:15 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	*arg_numbers(int ac, char **av)
{
	if (ac == 2)
		return (int_tab_one_arg(ac, av));
	else
		return (int_tab_two_arg_plus(ac, av));
	return (0);
}

int	int_tab_size(int ac, char **av)
{
	char	**num;
	int		size;

	size = 0;
	if (ac > 2)
		return (ac - 1);
	num = ft_split(av[1], ' ');
	while (num[size])
		size++;
	free_all(num);
	return (size);
}

int	*int_tab_one_arg(int ac, char **av)
{
	char	**num;
	int		*tab;
	int		i;

	num = ft_split(av[1], ' ');
	i = 0;
	while (num[i])
		i++;
	tab = malloc(sizeof(int) * i);
	if (!tab)
		return (0);
	i = 0;
	while (num[i])
	{
		tab[i] = ft_atoi(num[i]);
		i++;
	}
	free_all(num);
	return (indexing_tab(tab, ac, av));
}

int	*int_tab_two_arg_plus(int ac, char **av)
{
	int	*tab;
	int	i;

	tab = malloc(sizeof(int) * ac - 1);
	if (!tab)
		return (0);
	i = 1;
	while (i < ac)
	{
		tab[i - 1] = ft_atoi(av[i]);
		i++;
	}
	return (indexing_tab(tab, ac, av));
}

t_list	*create_list(int ac, char **av)
{
	int			i;
	int			*tab;
	int			size;
	int			*buffer;
	t_list		*tab_a;

	tab = arg_numbers(ac, av);
	tab_a = NULL;
	size = int_tab_size(ac, av);
	i = -1;
	while (++i < size)
	{
		buffer = malloc(sizeof(int));
		if (!buffer)
		{
			free(tab);
			return (0);
		}
		*buffer = tab[i];
		ft_lstadd_back(&tab_a, ft_lstnew((buffer)));
	}
	free(tab);
	return (tab_a);
}
