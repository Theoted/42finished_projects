/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:28:46 by tdeville          #+#    #+#             */
/*   Updated: 2022/01/27 09:58:53 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	increment_char_moves(t_mlx_data *data)
{
	if (data->character_move == 0)
		data->character_move++;
	else if (data->character_move == 1)
		data->character_move++;
	else if (data->character_move == 2)
		data->character_move = 0;
	if (data->bat_anim == 0)
		data->bat_anim = 1;
	else if (data->bat_anim == 1)
		data->bat_anim = 0;
}

void	direction_move(t_mlx_data data, int n)
{
	if (data.direction == 1 && n == 0)
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.sprites.right1_sprite, data.x, data.y);
	else if (data.direction == 0 && n == 0)
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.sprites.left1_sprite, data.x, data.y);
	else if (data.direction == 1 && n == 1)
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.sprites.right2_sprite, data.x, data.y);
	else if (data.direction == 0 && n == 1)
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.sprites.left2_sprite, data.x, data.y);
	else if (data.direction == 1 && n == 2)
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.sprites.right3_sprite, data.x, data.y);
	else if (data.direction == 0 && n == 2)
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.sprites.left3_sprite, data.x, data.y);
}

void	character_moves(t_mlx_data data)
{
	if (data.character_move == 0)
		direction_move(data, 0);
	else if (data.character_move == 1)
		direction_move(data, 1);
	else if (data.character_move == 2)
		direction_move(data, 2);
}

void	put_image(t_mlx_data data, int n)
{
	if (n == 1)
		mlx_put_image_to_window
					(data.mlx_ptr, data.win_ptr,
					data.img_ptr_1, data.x, data.y);
	if (n == 2)
		mlx_put_image_to_window
					(data.mlx_ptr, data.win_ptr,
					data.img_ptr_0, data.x, data.y);
	if (n == 3)
		mlx_put_image_to_window
					(data.mlx_ptr, data.win_ptr,
					data.img_ptr_c, data.x, data.y);
	if (n == 4)
		character_moves(data);
	if (n == 5)
		mlx_put_image_to_window
					(data.mlx_ptr, data.win_ptr,
					data.img_ptr_e, data.x + 5, data.y + 5);
	if (n == 9)
		enemy_animation(&data);
}

void	draw_map(t_mlx_data data)
{
	int	i;
	int	j;

	i = -1;
	while (data.matrix[++i])
	{
		j = -1;
		data.x = 0;
		while (data.matrix[i][++j])
		{
			put_image_condition(data, i, j);
			data.x += 64;
		}
		data.y += 64;
	}
	draw_steps(&data);
}
