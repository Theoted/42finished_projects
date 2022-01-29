/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:50:43 by tdeville          #+#    #+#             */
/*   Updated: 2022/01/27 09:54:18 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx_data	init_data(char *map)
{
	t_mlx_data	data;

	data.matrix = parse_map(map);
	data.matrix_x = get_x(data.matrix) * 64;
	data.matrix_y = get_y(data.matrix) * 64;
	data.sx = 64;
	data.sy = 64;
	data.y = 0;
	data.collectible = 0;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window
		(data.mlx_ptr, data.matrix_x, data.matrix_y, "so_long");
	data.collectible_count = collectibles_count(data);
	data.moves = 0;
	data.character_move = 0;
	data.direction = 0;
	data.enemy_direction = 0;
	data.steps = 0;
	data.bat_anim = 0;
	return (data);
}

t_mlx_data	init_sprites(t_mlx_data data)
{
		data.img_ptr_1 = mlx_xpm_file_to_image
		(data.mlx_ptr, "src/assets/ground1.xpm", &data.sx, &data.sy);
		data.img_ptr_0 = mlx_xpm_file_to_image
		(data.mlx_ptr, "src/assets/wall.xpm", &data.sx, &data.sy);
		data.img_ptr_c = mlx_xpm_file_to_image
		(data.mlx_ptr, "src/assets/collectible.xpm", &data.sx, &data.sy);
		data.img_ptr_p = mlx_xpm_file_to_image
		(data.mlx_ptr, "src/assets/run1_R.xpm", &data.sx, &data.sy);
		data.img_ptr_e = mlx_xpm_file_to_image
		(data.mlx_ptr, "src/assets/exit.xpm", &data.sx, &data.sy);
	return (data);
}

t_mlx_sprites	init_char_moves(t_mlx_data data)
{
	data.sprites.left1_sprite = mlx_xpm_file_to_image
		(data.mlx_ptr, "src/assets/run1_L.xpm", &data.sx, &data.sy);
	data.sprites.left2_sprite = mlx_xpm_file_to_image
		(data.mlx_ptr, "src/assets/run2_L.xpm", &data.sx, &data.sy);
	data.sprites.left3_sprite = mlx_xpm_file_to_image
		(data.mlx_ptr, "src/assets/run3_L.xpm", &data.sx, &data.sy);
	data.sprites.right1_sprite = mlx_xpm_file_to_image
		(data.mlx_ptr, "src/assets/run1_R.xpm", &data.sx, &data.sy);
	data.sprites.right2_sprite = mlx_xpm_file_to_image
		(data.mlx_ptr, "src/assets/run2_R.xpm", &data.sx, &data.sy);
	data.sprites.right3_sprite = mlx_xpm_file_to_image
		(data.mlx_ptr, "src/assets/run3_R.xpm", &data.sx, &data.sy);
	return (data.sprites);
}

t_mlx_enemy	init_enemy(t_mlx_data data)
{
	data.enemy.bat1 = mlx_xpm_file_to_image
		(data.mlx_ptr, "src/assets/bat1.xpm", &data.sx, &data.sy);
	data.enemy.bat2 = mlx_xpm_file_to_image
		(data.mlx_ptr, "src/assets/bat2.xpm", &data.sx, &data.sy);
	return (data.enemy);
}
