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
ft_printf_itoa_unsigned.c ft_printf_make_mem.c ft_printf_split_format.c 

FT = libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c \
libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c \
libft/ft_putstr_fd.c libft/ft_strclr.c libft/ft_strequ.c libft/ft_memnclr.c \
libft/ft_strnequ.c libft/ft_toupper.c libft/ft_isalpha.c libft/ft_isdigit.c \
libft/ft_putchar.c libft/ft_putendl.c libft/ft_putnbr.c libft/ft_putstr.c \
libft/ft_strcat.c libft/ft_strcpy.c libft/ft_strlen.c libft/ft_strncpy.c \
libft/ft_tolower.c libft/ft_strlenint.c libft/ft_strncat.c libft/ft_strcmp.c \
libft/ft_strncmp.c libft/ft_strlcat.c libft/ft_strdup.c libft/ft_bzero.c \
libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memccpy.c libft/ft_memset.c \
libft/ft_memchr.c libft/ft_memcmp.c libft/ft_strchr.c libft/ft_strrchr.c \
libft/ft_strstr.c libft/ft_strnstr.c libft/ft_atoi.c libft/ft_memalloc.c \
libft/ft_memdel.c libft/ft_strnew.c libft/ft_strdel.c libft/ft_strsplit.c \
libft/ft_strtrim.c libft/ft_strsub.c libft/ft_strjoin.c libft/ft_itoa.c \
libft/ft_striter.c libft/ft_striteri.c libft/ft_strmap.c libft/ft_strmapi.c \
libft/ft_lstnew.c libft/ft_lstdelone.c libft/ft_lstdel.c libft/ft_lstadd.c \
libft/ft_lstiter.c libft/ft_lstmap.c libft/ft_lstpush.c libft/ft_lstlen.c \
libft/ft_atoi_16.c libft/get_next_line.c

OBJECTS = $(OB:.c=.o)

all: $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c -o $@ $<

$(NAME): $(OBJECTS) libft/libft.a
	@ar rc $(NAME) $(OBJECTS) $(FT)
	@ranlib $(NAME)

clean:
	rm -rf $(OBJECTS)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

libft/libft.a:
	@make -C libft

re: fclean all
