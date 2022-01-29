/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 08:52:01 by tdeville          #+#    #+#             */
/*   Updated: 2021/11/23 12:06:49 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "Libft/libft.h"

int					char_print(char c);
int					string_print(char *s);
int					hexa_print(long long n, int caps);
int					num_print(int n, int bytes_read);
int					unsigned_num_print(unsigned int n, int bytes_read);
unsigned long long	int_length(unsigned long long n);
char				*rev_tab(char *tab);
char				*dec_to_hex_converter(unsigned long n, int caps);
int					check_sign(char current_char, va_list va_params);
int					check_sign2(char current_char, va_list va_params);
int					ft_printf(const char *arg, ...);
int					print_mem(unsigned long long n, int bytes_read);
int					ft_printf(const char *arg, ...);

#endif