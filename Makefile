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
FT = libft/ft_isalnum.o libft/ft_isascii.o libft/ft_isprint.o \
libft/ft_putchar_fd.o libft/ft_putendl_fd.o libft/ft_putnbr_fd.o \
libft/ft_putstr_fd.o libft/ft_strclr.o libft/ft_strequ.o libft/ft_memnclr.o \
libft/ft_strnequ.o libft/ft_toupper.o libft/ft_isalpha.o libft/ft_isdigit.o \
libft/ft_putchar.o libft/ft_putendl.o libft/ft_putnbr.o libft/ft_putstr.o \
libft/ft_strcat.o libft/ft_strcpy.o libft/ft_strlen.o libft/ft_strncpy.o \
libft/ft_tolower.o libft/ft_strlenint.o libft/ft_strncat.o libft/ft_strcmp.o \
libft/ft_strncmp.o libft/ft_strlcat.o libft/ft_strdup.o libft/ft_bzero.o \
libft/ft_memcpy.o libft/ft_memmove.o libft/ft_memccpy.o libft/ft_memset.o \
libft/ft_memchr.o libft/ft_memcmp.o libft/ft_strchr.o libft/ft_strrchr.o \
libft/ft_strstr.o libft/ft_strnstr.o libft/ft_atoi.o libft/ft_memalloc.o \
libft/ft_memdel.o libft/ft_strnew.o libft/ft_strdel.o libft/ft_strsplit.o \
libft/ft_strtrim.o libft/ft_strsub.o libft/ft_strjoin.o libft/ft_itoa.o \
libft/ft_striter.o libft/ft_striteri.o libft/ft_strmap.o libft/ft_strmapi.o \
libft/ft_lstnew.o libft/ft_lstdelone.o libft/ft_lstdel.o libft/ft_lstadd.o \
libft/ft_lstiter.o libft/ft_lstmap.o libft/ft_lstpush.o libft/ft_lstlen.o \
libft/ft_atoi_16.o libft/get_next_line.o

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C libft
	@ar rc $(NAME) $(OBJECTS) $(FT)
	@ranlib $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJECTS)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all
