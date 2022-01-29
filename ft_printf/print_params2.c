/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_params2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:40:49 by tdeville          #+#    #+#             */
/*   Updated: 2021/11/23 14:47:59 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_mem(unsigned long long n, int bytes_read)
{
	char	*tab;
	int		i;

	i = 0;
	tab = dec_to_hex_converter(n, 0);
	if (!tab)
		return (0);
	write(1, "0x", 2);
	bytes_read += 2;
	while (tab[i])
	{
		write(1, &tab[i], 1);
		i++;
		bytes_read++;
	}
	free(tab);
	return (bytes_read);
}
