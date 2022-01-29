/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:56:52 by tdeville          #+#    #+#             */
/*   Updated: 2022/01/27 10:18:26 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_mlx_data	data;

	if (ac != 2 || check_map_name(av[1]))
	{
		printf("Error\nInvalid arguments or map name\n");
		return (1);
	}
	data = init_data(av[1]);
	data = init_sprites(data);
	data.sprites = init_char_moves(data);
	data.enemy = init_enemy(data);
	if (check_error(data))
	{
		printf("Error\nInvalid map\n");
		close_exe(&data);
	}
	draw_enemy(&data);
	draw_map(data);
	mlx_key_hook(data.win_ptr, deal_key, &data);
	mlx_hook(data.win_ptr, 17, 0, close_exe, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
