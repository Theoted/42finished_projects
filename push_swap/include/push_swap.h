/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:03:42 by tdeville          #+#    #+#             */
/*   Updated: 2022/01/12 10:51:08 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../Libft/libft.h"

// *MAIN* //
t_list	*parse_arg(int ac, char **av);
int		check_sort(t_list *tab_a);
void	clear_lists(t_list **tab_a, t_list **tab_b);

// *PARSE_ARG* //
t_list	*create_list(int ac, char **av);
int		*int_tab_one_arg(int ac, char **av);
int		int_tab_size(int ac, char **av);
int		*int_tab_two_arg_plus(int ac, char **av);
int		*arg_numbers(int ac, char **av);

// *ERRORS* //
int		error(int ac, char **av);
int		one_arg_error_cases(char **av);
int		multiple_arg_error_cases(int ac, char **av);
int		isnt_int(char *number);
int		check_error(char *s1, char *s2);

// *OPERATIONS* //
void	swap_a(t_list *tab_a);
void	swap_b(t_list *tab_b);
void	sa_sb(t_list *tab_a, t_list *tab_b);
void	push_a(t_list **tab_a, t_list **tab_b);
void	push_b(t_list **tab_b, t_list **tab_a);

void	rotate_a(t_list **tab_a);
void	rotate_b(t_list **tab_b);
void	ra_rb(t_list **tab_a, t_list **tab_b);

void	reverse_rotate_a(t_list **tab_a);
void	reverse_rotate_b(t_list **tab_b);
void	rra_rrb(t_list **tab_a, t_list **tab_b);

// *TEST FUNCTIONS* //
void	ft_lstprint(t_list *lst);
void	ft_lstprint_both(t_list *lst_a, t_list *lst_b);
void	rra_rrb(t_list **tab_a, t_list **tab_b);

// *UTILS* //
t_list	*ft_lstsecondlast(t_list *lst);
void	free_all(char **num);
void	del(void *content);
int		*indexing_tab(int *tab, int ac, char **av);
int		find_index(t_list *tab, int min, int max);
int		find_closest(t_list *tab, int min, int max);
long	l_atoi(const char *str);
int		write_error(char **s);

// *PUSH_SWAP* //
void	ft_radix(t_list **tab_a, t_list **tab_b);
void	big_sort(t_list **tab_a, t_list **tab_b);
void	big_sort_push_b(t_list **tab_a, t_list **tab_b, int min, int *check);
void	big_sort_push_a(t_list **tab_a, t_list **tab_b);
void	little_sort(t_list **tab_a);
void	medium_sort(t_list **tab_a, t_list **tab_b);

#endif