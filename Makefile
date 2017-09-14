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

OB = ft_printf.c ft_printf_data_c.c ft_printf_data_d.c \
ft_printf_data_p_u_x_o.c ft_printf_data_print.c ft_printf_data_s_wchar_t.c \
ft_printf_format_parsing.c ft_printf_help1.c ft_printf_itoa.c \
ft_printf_itoa_unsigned.c ft_printf_make_mem.c ft_printf_split_format.c \
ft_bzero.c ft_isdigit.c ft_itoa.c ft_memalloc.c ft_strcmp.c ft_strcmp.c \
ft_strcpy.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strnew.c

OBJECTS = $(OB:.c=.o)

all: $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c -o $@ $<

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS) $(FT)
	@ranlib $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
