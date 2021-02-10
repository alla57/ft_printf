# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alboumed <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/20 21:45:39 by alboumed          #+#    #+#              #
#    Updated: 2020/09/20 21:45:49 by alboumed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

SRC_PATH	=	ft_printf.c				\
				types_1.c				\
				types_2.c				\
				minus_behaviors.c		\
				ft_libft_1.c			\
				ft_libft_2.c			\
				flag_checker_1.c		\
				flag_checker_2.c		\

SRC = $(addprefix src/,$(SRC_PATH))

OBJ		=	$(SRC:%.c=%.o)

CFLAGS	+= -Wall -Wextra -Werror -I./include

NAME	=	libftprintf.a

BUILD_DIR	=	build

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

bonus: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

re:	fclean $(NAME)

.PHONY: all clean fclean re
