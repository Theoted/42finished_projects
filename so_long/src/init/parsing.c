/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:39:51 by tdeville          #+#    #+#             */
/*   Updated: 2022/01/28 09:47:16 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_x(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[0][i])
		i++;
	return (i);
}

int	get_y(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

int	get_file(int fd, char **file)
{
	int		r;
	int		i;
	char	buffer[2];
	char	*tmp;

	i = 0;
	r = read(fd, buffer, 1);
	if (r == 0)
		return (1);
	while (r)
	{
		buffer[1] = '\0';
		if (!*file)
			*file = ft_substr(buffer, 0, ft_strlen(buffer));
		else
		{
			tmp = *file;
			*file = ft_strjoin(*file, buffer);
			free(tmp);
		}
		r = read(fd, buffer, 1);
	}
	return (0);
}

char	**parse_map(char *map)
{
	char	**matrix;
	int		fd;
	char	*file;

	file = NULL;
	if (open(map, O_RDONLY | O_DIRECTORY) > 0)
		error_map();
	fd = open(map, O_RDONLY);
	if (get_file(fd, &file) || fd == -1)
		error_map();
	close(fd);
	if (check_n(file))
	{
		free(file);
		error_map();
	}
	matrix = ft_split(file, '\n');
	free(file);
	return (matrix);
}
