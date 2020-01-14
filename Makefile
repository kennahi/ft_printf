# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kennahi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/31 15:28:04 by kennahi           #+#    #+#              #
#    Updated: 2020/01/09 20:20:49 by kennahi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf_utils.c ft_printf_utils_2.c ft_printf_utils_3.c converter.c ft_printf.c dispecifier1.c dispecifier2.c uspecifier1.c sspecifier1.c addfuncspecifier.c cspecifier1.c xspecifier.c pspecifier.c

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	gcc -Wall -Wextra -Werror -c $^

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
