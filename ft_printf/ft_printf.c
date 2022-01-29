/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 08:51:51 by tdeville          #+#    #+#             */
/*   Updated: 2021/11/23 13:37:49 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_sign(char current_char, va_list va_params)
{
	int	bytes_read;

	bytes_read = 0;
	if (current_char == 'c')
		bytes_read = char_print(va_arg(va_params, int));
	else if (current_char == 's')
		bytes_read = string_print(va_arg(va_params, char *));
	else if (current_char == 'p')
		bytes_read = print_mem((unsigned long long)
				va_arg(va_params, void*), bytes_read);
	else if (current_char == 'd' || current_char == 'i')
		bytes_read = num_print(va_arg(va_params, int), bytes_read);
	else
		return (check_sign2(current_char, va_params));
	return (bytes_read);
}

int	check_sign2(char current_char, va_list va_params)
{
	int	bytes_read;

	bytes_read = 0;
	if (current_char == 'u')
		bytes_read = unsigned_num_print(va_arg(va_params, unsigned int),
				bytes_read);
	else if (current_char == 'x')
		bytes_read = hexa_print(va_arg(va_params, unsigned int), 0);
	else if (current_char == 'X')
		bytes_read = hexa_print(va_arg(va_params, unsigned int), 1);
	else if (current_char == '%')
		bytes_read = char_print(current_char);
	else
		bytes_read = char_print(current_char);
	return (bytes_read);
}

int	ft_printf(const char *arg, ...)
{
	va_list	va_params;
	int		i;
	int		bytes_read;

	bytes_read = 0;
	va_start(va_params, arg);
	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] != '%')
		{
			write(1, &arg[i], 1);
			bytes_read++;
		}
		else
		{
			i++;
			bytes_read += check_sign(arg[i], va_params);
		}
		if (!arg[i])
			return (bytes_read);
		i++;
	}
	va_end(va_params);
	return (bytes_read);
}
