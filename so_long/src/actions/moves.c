/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:55:44 by tdeville          #+#    #+#             */
/*   Updated: 2022/01/27 09:58:47 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	deal_key(int key, t_mlx_data *data)
{
	if (key == 13)
		move_up(data);
	if (key == 1)
		move_down(data);
	if (key == 0)
		move_left(data);
	if (key == 2)
		move_right(data);
	if (key == 53)
		close_exe(data);
	return (0);
}

void	move_up(t_mlx_data *data)
{
	int		i;
	int		j;

	i = get_y_pos(*data);
	j = get_x_pos(*data);
	if (data->matrix[i - 1][j] == '0' || data->matrix[i - 1][j] == 'C')
	{
		data->moves++;
		if (data->matrix[i - 1][j] == 'C')
				data->collectible++;
		data->matrix[i][j] = '0';
		data->matrix[i - 1][j] = 'P';
		increment_char_moves(data);
		draw_map(*data);
	}
	if (data->matrix[i - 1][j] == 'E' &&
		data->collectible == data->collectible_count)
		close_exe(data);
	if (data->matrix[i - 1][j] == '9')
	{
		printf("You hit an enemy...\n");
		close_exe(data);
	}
}

void	move_down(t_mlx_data *data)
{
	int		i;
	int		j;

	i = get_y_pos(*data);
	j = get_x_pos(*data);
	if (data->matrix[i + 1][j] == '0' || data->matrix[i + 1][j] == 'C')
	{
		data->moves++;
		if (data->matrix[i + 1][j] == 'C')
			data->collectible++;
		data->matrix[i][j] = '0';
		data->matrix[i + 1][j] = 'P';
		increment_char_moves(data);
		draw_map(*data);
	}
	if (data->matrix[i + 1][j] == 'E' &&
		data->collectible == data->collectible_count)
		close_exe(data);
	if (data->matrix[i + 1][j] == '9')
	{
		printf("You hit an enemy...\n");
		close_exe(data);
	}
}

void	move_left(t_mlx_data *data)
{
	int		i;
	int		j;

	i = get_y_pos(*data);
	j = get_x_pos(*data);
	if (data->matrix[i][j - 1] == '0' || data->matrix[i][j - 1] == 'C')
	{
		data->moves++;
		if (data->matrix[i][j - 1] == 'C')
			data->collectible++;
		data->matrix[i][j] = '0';
		data->matrix[i][j - 1] = 'P';
		data->direction = 0;
		increment_char_moves(data);
		draw_map(*data);
	}
	if (data->matrix[i][j - 1] == 'E' &&
		data->collectible == data->collectible_count)
		close_exe(data);
	if (data->matrix[i][j - 1] == '9')
	{
		printf("You hit an enemy...\n");
		close_exe(data);
	}
}

void	move_right(t_mlx_data *data)
{
	int		i;
	int		j;

	i = get_y_pos(*data);
	j = get_x_pos(*data);
	if (data->matrix[i][j + 1] == '0' || data->matrix[i][j + 1] == 'C')
	{
		data->moves++;
		if (data->matrix[i][j + 1] == 'C')
			data->collectible++;
		data->matrix[i][j] = '0';
		data->matrix[i][j + 1] = 'P';
		data->direction = 1;
		increment_char_moves(data);
		draw_map(*data);
	}
	if (data->matrix[i][j + 1] == 'E' &&
		data->collectible == data->collectible_count)
		close_exe(data);
	if (data->matrix[i][j + 1] == '9')
	{
		printf("You hit an enemy...\n");
		close_exe(data);
	}
}
