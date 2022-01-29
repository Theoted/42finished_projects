/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:31:21 by tdeville          #+#    #+#             */
/*   Updated: 2022/01/28 09:45:37 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_exe(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_all(data->matrix);
	exit(1);
}

int	error_map(void)
{
	printf("Error\nInvalid map\n");
	exit(1);
}

void	draw_steps(t_mlx_data *data)
{
	char	*steps;
	char	*c_max;
	char	*c_current;

	steps = ft_itoa(data->moves);
	c_max = ft_itoa(data->collectible_count);
	c_current = ft_itoa(data->collectible);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 20, 0xFFFFFF, "Steps:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 55, 20, 0xFFFFFF, steps);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 40, 0xFFFFFF,
		"Collectibles:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 110, 40, 0xFFFFFF, c_current);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 123, 40, 0xFFFFFF, "/");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 130, 40, 0xFFFFFF, c_max);
	free(c_max);
	free(steps);
	free(c_current);
}

void	put_image_condition(t_mlx_data data, int i, int j)
{
	if (data.matrix[i][j] != '1')
		put_image(data, 1);
	if (data.matrix[i][j] == '1')
		put_image(data, 2);
	if (data.matrix[i][j] == 'C')
		put_image(data, 3);
	if (data.matrix[i][j] == 'P')
		put_image(data, 4);
	if (data.matrix[i][j] == 'E')
		put_image(data, 5);
	if (data.matrix[i][j] == '9')
		put_image(data, 9);
}
