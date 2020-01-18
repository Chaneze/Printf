# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: charoua <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/16 10:52:10 by charoua           #+#    #+#              #
#    Updated: 2020/01/18 15:20:12 by charoua          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Werror -Wextra -Wall

SRC = ./Sources/
SRCS = $(SRC)printf.c \
		$(SRC)get_param.c \
		$(SRC)/Type/ft_character.c \
		$(SRC)/Type/ft_string.c \
		$(SRC)/Type/ft_address.c \
		$(SRC)/Type/ft_int_and_hex.c \
		$(SRC)/Itoa/ft_itoa_address_hex.c \
		$(SRC)/Itoa/ft_itoa_int.c \
		$(SRC)/Itoa/ft_itoa_unsigned_int.c \
		$(SRC)/Itoa/ft_itoa_hex.c \
		$(SRC)/Utils/ft_strlen.c \
		$(SRC)/Utils/ft_putstr.c \
		$(SRC)/Utils/ft_atoi.c

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

INC = ./Includes

all: $(NAME)

$(NAME): $(OBJ)
		@ar rc $(NAME) $^
		@ranlib $(NAME)

.o: .c
		@$(CC) $(CFLAGS) -I$(INC) -o $@ -c $<

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT: $(OBJ)
