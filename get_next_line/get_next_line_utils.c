/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:09:11 by tdeville          #+#    #+#             */
/*   Updated: 2022/01/19 16:18:24 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str, int n)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	if (n == 0)
	{
		while (str[i])
			i++;
		return (i);
	}
	else
	{
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i] && str[i] == '\n')
			i++;
		return (i);
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * ((ft_strlen(s1, 0) + ft_strlen(s2, 0)) + 1));
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	if ((char)c == '\0')
		return ((char *)&s[ft_strlen(s, 0)]);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			length;
	size_t			str_len;
	unsigned int	j;
	char			*str;

	i = -1;
	j = start;
	str_len = ft_strlen(s, 0);
	length = len;
	if (!s)
		return (0);
	if (str_len < len)
		length = str_len - 1;
	str = malloc((sizeof(char) * length) + 1);
	if (!str)
		return (0);
	while (++i < len && s[j] && (j < str_len))
		str[i] = s[j++];
	str[i] = '\0';
	return (str);
}
