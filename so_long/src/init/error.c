/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:21:46 by tdeville          #+#    #+#             */
/*   Updated: 2022/01/27 10:19:53 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_p(t_mlx_data data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (data.matrix[i])
	{
		j = 0;
		while (data.matrix[i][j])
		{
			if (data.matrix[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	if (count == 1)
		return (0);
	else
		return (1);
}

int	check_c(t_mlx_data data)
{
	int	i;
	int	j;

	i = 0;
	while (data.matrix[i])
	{
		j = 0;
		while (data.matrix[i][j])
		{
			if (data.matrix[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_e(t_mlx_data data)
{
	int	i;
	int	j;

	i = 0;
	while (data.matrix[i])
	{
		j = 0;
		while (data.matrix[i][j])
		{
			if (data.matrix[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_1(t_mlx_data data)
{
	int	i;
	int	j;

	i = 0;
	while (data.matrix[i])
	{
		j = 0;
		while (data.matrix[i][j])
		{
			if (((i == 0 || i == get_y(data.matrix) - 1)
					&& data.matrix[i][j] != '1')
					|| ((j == 0 || j == get_x(data.matrix) - 1)
					&& data.matrix[i][j] != '1'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_error(t_mlx_data data)
{
	if ((!check_1(data)) && (!check_c(data))
		&& (!check_e(data)) && (!check_p(data))
		&& (!check_size(data)) && (!check_char(data.matrix)))
		return (0);
	else
		return (1);
}
