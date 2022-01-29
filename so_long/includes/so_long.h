/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:57:07 by tdeville          #+#    #+#             */
/*   Updated: 2022/01/28 09:45:51 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "mlx.h"
# include "libft.h"

// Bonus
# include <time.h>

// Structs
typedef struct s_mlx_sprites
{
	void	*left1_sprite;
	void	*left2_sprite;
	void	*left3_sprite;
	void	*right1_sprite;
	void	*right2_sprite;
	void	*right3_sprite;
}			t_mlx_sprites;

typedef struct s_mlx_enemy
{
	void	*bat1;
	void	*bat2;
}	t_mlx_enemy;

typedef struct s_mlx_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				sx;
	int				sy;
	int				y;
	int				x;
	int				matrix_x;
	int				matrix_y;
	char			**matrix;
	void			*img_ptr_1;
	void			*img_ptr_0;
	void			*img_ptr_e;
	void			*img_ptr_c;
	void			*img_ptr_p;
	int				collectible;
	int				collectible_count;
	int				moves;
	int				character_move;
	int				direction;
	int				enemy_direction;
	int				random_number;
	int				steps;
	int				bat_anim;
	t_mlx_sprites	sprites;
	t_mlx_enemy		enemy;
}			t_mlx_data;

// Parsing
char			**parse_map(char *map);
int				get_file(int fd, char **file);
int				get_x(char **matrix);
int				get_y(char **matrix);

// Data_init
t_mlx_data		init_data(char *map);
t_mlx_data		init_sprites(t_mlx_data data);
t_mlx_sprites	init_char_moves(t_mlx_data data);
t_mlx_enemy		init_enemy(t_mlx_data data);

// Draw map
void			draw_map(t_mlx_data data);
void			put_image(t_mlx_data data, int n);
void			increment_char_moves(t_mlx_data *data);
void			direction_move(t_mlx_data data, int n);

// Enemy
void			draw_enemy(t_mlx_data *data);
void			enemy_animation(t_mlx_data *data);

// Moves
int				deal_key(int key, t_mlx_data *data);
void			move_up(t_mlx_data *data);
void			move_down(t_mlx_data *data);
void			move_left(t_mlx_data *data);
void			move_right(t_mlx_data *data);

// Utils
int				close_exe(t_mlx_data *data);
void			free_all(char **str);
int				get_x_pos(t_mlx_data data);
int				get_y_pos(t_mlx_data data);
int				collectibles_count(t_mlx_data data);
int				integer_len(int n);
void			draw_steps(t_mlx_data *data);
void			put_image_condition(t_mlx_data data, int i, int j);
int				error_map(void);

// Error
int				check_1(t_mlx_data data);
int				check_e(t_mlx_data data);
int				check_c(t_mlx_data data);
int				check_p(t_mlx_data data);
int				check_error(t_mlx_data data);
int				check_size(t_mlx_data data);
int				check_map_name(char *map);
int				check_char(char **map);
int				check_n(char *map);

#endif