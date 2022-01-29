# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 11:15:22 by tdeville          #+#    #+#              #
#    Updated: 2022/01/25 10:22:17 by tdeville         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
HEADER	= include/push_swap.h libft/libft.h
LIBFT	= Libft

SRCS	=	src/main.c src/push_swap/radix.c src/push_swap/sorts.c \
			src/push_swap_init/operations1.c src/push_swap_init/operations2.c \
			src/push_swap_init/operations3.c src/push_swap_init/parse_arg.c \
			src/push_swap_utils/push_swap_utils1.c src/push_swap_utils/push_swap_utils2.c \
			src/push_swap_init/error.c

OBJS		= ${SRCS:.c=.o}

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

all: maker ${NAME}

%.o : %.c	${HEADER}
		${CC} ${CFLAGS} -c $< -o $@


${NAME}: ${OBJS} Libft/libft.a
		${CC} ${CFLAGS} ${OBJS} -o $@ Libft/libft.a


maker:	
		${MAKE} -C ${LIBFT}

clean:	
		rm -f ${OBJS}
		${MAKE} clean -C ${LIBFT}

fclean:	clean
		rm -f ${NAME}
		${MAKE} fclean -C ${LIBFT}

re:		fclean all

.PHONY: all clean fclean re maker
