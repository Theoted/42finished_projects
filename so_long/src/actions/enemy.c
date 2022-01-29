/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:40:01 by tdeville          #+#    #+#             */
/*   Updated: 2022/01/27 09:58:43 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_enemy(t_mlx_data *data)
{
	int	i;
	int	j;
	int	c;
	int	d;

	i = 0;
	c = 0;
	d = get_x(data->matrix) / 4;
	while (data->matrix[i])
	{
		j = 0;
		c = i;
		while (data->matrix[i][j])
		{
			if ((c == d || c == (d * 2) || c == (d * 3) || c == (d * 4))
				&& (i % 2 == 0) && data->matrix[i][j] == '0')
				data->matrix[i][j] = '9';
			j++;
			c++;
		}
		i++;
	}
}

void	enemy_animation(t_mlx_data *data)
{
	if (data->bat_anim == 0)
		mlx_put_image_to_window
				(data->mlx_ptr, data->win_ptr,
				data->enemy.bat1, data->x, data->y);
	else if (data->bat_anim == 1)
		mlx_put_image_to_window
				(data->mlx_ptr, data->win_ptr,
				data->enemy.bat2, data->x, data->y);
}
