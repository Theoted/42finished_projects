/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:54:39 by tdeville          #+#    #+#             */
/*   Updated: 2022/01/19 09:52:56 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	isnt_int(char *number)
{
	int	i;

	i = 0;
	if (number[0] == '-')
		i++;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_error(char *s1, char *s2)
{
	if (!s2)
	{
		if (isnt_int(s1)
			|| (l_atoi(s1) > 2147483647) || (l_atoi(s1) < -2147483648))
			return (1);
	}
	else if (ft_atoi(s1) == ft_atoi(s2) || isnt_int(s1)
		|| isnt_int(s2)
		|| (l_atoi(s1) > 2147483647) || (l_atoi(s1) < -2147483648)
		|| (l_atoi(s2) > 2147483647) || (l_atoi(s2) < -2147483648))
		return (1);
	return (0);
}

int	one_arg_error_cases(char **av)
{
	char	**s;
	int		i;
	int		j;

	i = -1;
	s = ft_split(av[1], ' ');
	while (s[++i])
	{
		j = i;
		while (s[++j])
		{
			if (check_error(s[i], s[j]))
			{
				write(2, "Error\n", 6);
				free_all(s);
				return (1);
			}
		}
	}
	free_all(s);
	return (0);
}

int	multiple_arg_error_cases(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = i;
		while (++j < ac)
		{
			if (check_error(av[i], av[j]))
			{
				write(2, "Error\n", 6);
				return (1);
			}
		}
	}
	return (0);
}

int	error(int ac, char **av)
{
	char	**s;

	s = NULL;
	if (ac == 2)
	{
		s = ft_split(av[1], ' ');
		if (!s[1])
		{
			if (check_error(s[0], NULL))
				return (write_error(s));
		}	
		if (one_arg_error_cases(av))
		{
			free_all(s);
			return (1);
		}
	}
	else
		if (multiple_arg_error_cases(ac, av))
			return (1);
	if (s)
		free_all(s);
	return (0);
}
