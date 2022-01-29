/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 08:52:11 by tdeville          #+#    #+#             */
/*   Updated: 2021/11/22 16:47:12 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_print(char c)
{
	write(1, &c, 1);
	return (1);
}

int	string_print(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	hexa_print(long long n, int caps)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	tab = dec_to_hex_converter(n, caps);
	if (caps == 2)
	{
		write (1, "0", 1);
		write (1, "x", 1);
		j = 2;
	}
	while (tab[i])
	{
		write(1, &tab[i], 1);
		i++;
	}
	free(tab);
	return (i + j);
}

int	num_print(int n, int bytes_read)
{
	unsigned long long	num;

	num = n;
	if (n < 0)
	{
		num = -num;
		write(1, "-", 1);
		bytes_read++;
	}
	if (num > 9)
		bytes_read = num_print(num / 10, ++bytes_read);
	else
		bytes_read++;
	char_print(num % 10 + '0');
	return (bytes_read);
}

int	unsigned_num_print(unsigned int n, int bytes_read)
{
	if (n > 9)
		bytes_read = unsigned_num_print(n / 10, ++bytes_read);
	else
		bytes_read++;
	char_print(n % 10 + '0');
	return (bytes_read);
}
