/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:31:39 by tdeville          #+#    #+#             */
/*   Updated: 2022/01/28 09:54:56 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_size(t_mlx_data data)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	while (data.matrix[i])
	{
		j = 0;
		size = 0;
		while (data.matrix[i][j])
		{
			size++;
			j++;
		}
		if (size != get_x(data.matrix))
			return (1);
		i++;
	}
	return (0);
}

int	check_map_name(char *map)
{
	int		i;
	int		j;
	char	check_name[4];

	i = ft_strlen(map);
	j = 4;
	while (j > 0)
	{
		check_name[j - 1] = map[i - 1];
		j--;
		i--;
	}
	if (!ft_strncmp(check_name, ".ber", 4))
		return (0);
	else
		return (1);
}

int	check_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'P'
				|| map[i][j] == 'E' || map[i][j] == 'C' || map[i][j] == '9')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_n(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}
