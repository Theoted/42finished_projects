# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 09:32:04 by tdeville          #+#    #+#              #
#    Updated: 2021/11/23 11:10:09 by tdeville         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

LIBFT	= Libft

SRCS	=	ft_printf.c \
			print_params.c \
			printf_utils.c \
			print_params2.c \

OBJS	= ${SRCS:.c=.o}

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra


${NAME}:	${OBJS}
		make -C ${LIBFT}
		cp Libft/libft.a ${NAME}
		ar rcs ${NAME} ${OBJS}

%.o : %.c	ft_printf.h
			${CC} ${CFLAGS} -c $< -o $@

all:	${NAME}

clean:
		rm -f ${OBJS}
		make clean -C ${LIBFT}

fclean:	clean
		rm -f ${NAME}
		make fclean -C ${LIBFT}

re:		fclean all

.PHONY: all clean fclean re 