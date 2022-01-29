/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 08:55:17 by tdeville          #+#    #+#             */
/*   Updated: 2021/11/23 10:25:51 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	int_length(unsigned long long n)
{
	unsigned long long	i;

	i = 0;
	if (n < 0)
		n = -n;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

char	*rev_tab(char *tab)
{
	size_t	i;
	size_t	j;
	char	tmp;

	i = -1;
	j = ft_strlen(tab) - 1;
	if (tab[0] == '-')
		i = 0;
	while (++i < (ft_strlen(tab) / 2))
	{
		tmp = tab[j];
		tab[j] = tab[i];
		tab[i] = tmp;
		j--;
	}
	return (tab);
}

char	*dec_to_hex_converter(unsigned long n, int caps)
{
	char					*base;
	char					*tab;
	int						i;
	unsigned long long		num;

	base = "0123456789ABCDEF";
	if (caps == 0 || caps == 2)
		base = "0123456789abcdef";
	i = 0;
	num = n;
	if (n < 0)
		num = -n;
	tab = ft_calloc(int_length(num) + 1, sizeof(char));
	if (!tab)
		return (0);
	while (num >= 16)
	{
		tab[i++] = base[num % 16];
		num /= 16;
	}
	tab[i] = base[num % 16];
	return (rev_tab(tab));
}
