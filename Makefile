# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nflan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 12:13:31 by nflan             #+#    #+#              #
#    Updated: 2022/02/24 12:07:59 by nflan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.h libft
vpath ft_%.c libft
vpath ft_%.o libft

sources = src/ft_check.c src/ft_chunks.c src/ft_double_triple.c src/ft_fill.c \
		src/ft_five.c src/ft_five_tools.c src/ft_manage_a.c src/ft_manage_b.c \
		src/ft_manage_b2.c src/ft_op.c src/ft_roll.c src/ft_utils.c src/main.c \
		src/print_debug.c src/ft_utils2.c src/ft_sort_clear.c src/ft_sort_rra.c

INC =	include/push_swap.h

LIBFT = libft/libft.a

OBJS = ${sources:.c=.o}

NAME = push_swap

#CC = gcc

#RM = rm -f

#CFLAGS = -Wall -Wextra -Werror

#.c.o :
#	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

$(NAME): ${OBJS} ${HEADER} ${LIBFT}
	${CC} ${CFLAGS} ${OBJS} -I ${INC} libft/libft.a -o ${NAME}

-include libft/Makefile

ft_%.o : ft_%.c
	gcc ${CFLAGS} -c $< -o $@

$(LIBFT) : ${SRCS} libft.h
	${MAKE} -C ./libft

clean:
	$(MAKE) clean -C libft/
	${RM} ${OBJS}

fclean:
	$(MAKE) fclean -C libft/
	${RM} ${NAME}
	${RM} ${OBJS}

re: fclean all

.PHONY: all clean fclean re
