# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/22 19:00:59 by dverbyts          #+#    #+#              #
#    Updated: 2017/08/22 19:01:01 by dverbyts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_printf_data_c.c ft_printf_data_d_u_o_x.c \
ft_printf_data_p.c ft_printf_data_s.c ft_printf_data_s_wchar_t.c \
ft_printf_format_parsing.c ft_printf_itoa.c ft_printf_make_mem.c \
ft_printf_split_format.c ft_printf_write_non_format.c

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
