# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afantes <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 22:48:12 by afantes           #+#    #+#              #
#    Updated: 2022/11/15 22:48:14 by afantes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_FILE = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_unsigned_int.c ft_hexadecimal.c \

OBJ_FILE = $(SRC_FILE:.c=.o)

$(NAME): $(OBJ_FILE)
	ar rc $(NAME) $(OBJ_FILE)

%.o : %.c ft_printf.h
	cc -Wall -Wextra -Werror -c $< -o $@

all: $(NAME)

clean :
	rm -f $(OBJ_FILE)

fclean : clean
	rm -f libftprintf.a

re : fclean all

.PHONEY : all clean fclean re
