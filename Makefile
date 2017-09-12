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
SRC = ft_printf.c ft_printf_data_c.c ft_printf_data_p_u_x_o.c \
ft_printf_data_d.c ft_printf_data_s_wchar_t.c ft_printf_format_parsing.c \
ft_printf_itoa.c ft_printf_itoa_unsigned.c ft_printf_make_mem.c \
ft_printf_split_format.c ft_printf_data_print.c ft_printf_help1.c
LIBFT = libft/libft.a
LIBFT_O = libft_o

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C libft
	mkdir libft_o && cd $(LIBFT_O) && ar -x ../$(LIBFT) && cd ../
	@ar rc $(NAME) $(OBJECTS) $(LIBFT_O)/*.o
	rm -rf $(LIBFT_O)
	ranlib $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJECTS)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all
