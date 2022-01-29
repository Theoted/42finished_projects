/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:57:21 by tdeville          #+#    #+#             */
/*   Updated: 2022/01/27 09:59:09 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	get_x_pos(t_mlx_data data)
{
	int	i;
	int	j;

	i = 0;
	while (data.matrix[i])
	{
		j = 0;
		while (data.matrix[i][j])
		{
			if (data.matrix[i][j] == 'P')
				break ;
			j++;
		}
		if (data.matrix[i][j] == 'P')
			break ;
		i++;
	}
	return (j);
}

int	get_y_pos(t_mlx_data data)
{
	int	i;
	int	j;

	i = 0;
	while (data.matrix[i])
	{
		j = 0;
		while (data.matrix[i][j])
		{
			if (data.matrix[i][j] == 'P')
				break ;
			j++;
		}
		if (data.matrix[i][j] == 'P')
			break ;
		i++;
	}
	return (i);
}

int	collectibles_count(t_mlx_data data)
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
			if (data.matrix[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	integer_len(int n)
{
	int	i;

	i = 0;
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	i++;
	return (i);
}
