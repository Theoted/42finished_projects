/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:08:28 by tdeville          #+#    #+#             */
/*   Updated: 2021/11/24 14:18:38 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	get_line(char **line, int fd, char *buffer)
{
	int			r;
	char		*tmp;

	r = read(fd, buffer, BUFFER_SIZE);
	while (r > 0)
	{
		buffer[r] = '\0';
		if (!*line)
			*line = ft_substr(buffer, 0, r);
		else
		{
			tmp = *line;
			*line = ft_strjoin(*line, buffer);
			free(tmp);
		}
		if (ft_strchr(*line, '\n'))
			break ;
		r = read(fd, buffer, BUFFER_SIZE);
	}
}

static char	*parse_line(char **line)
{
	char	*tmp;
	char	*mem;

	if (!*line)
		return (NULL);
	if (!ft_strchr(*line, '\n'))
	{
		if (*line[0] == '\0')
		{
			free(*line);
			*line = NULL;
			return (NULL);
		}
		tmp = ft_substr(*line, 0, ft_strlen(*line, 0));
		free(*line);
		*line = NULL;
		return (tmp);
	}
	mem = *line;
	tmp = ft_substr(*line, 0, ft_strlen(*line, 1));
	*line = ft_substr(*line, ft_strlen(*line, 1), ft_strlen(*line, 0));
	free(mem);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*str;
	char		buffer[BUFFER_SIZE + 1];

	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, buffer, 0) == -1)
		return (NULL);
	if (!line || !ft_strchr((const char *)line, '\n'))
		get_line(&line, fd, buffer);
	str = parse_line(&line);
	return (str);
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int fd;
	char *str;

	fd = open("file.txt", O_RDONLY);
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
	}
	close(fd);
}
