/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 17:04:45 by dverbyts          #+#    #+#             */
/*   Updated: 2017/08/01 17:04:46 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <inttypes.h>
# include <stddef.h>
# include "libft/libft.h"

typedef	struct			s_arg
{
	int					hh;
	int					h;
	int					l;
	int					ll;
	int					j;
	int					z;
	int					t;
	int					lll;
	int					re;
	int					prs;
	int					accuracy;
	int					width;
	int					minus;
	int					plus;
	int					spase;
	int					hash;
	int					zero;
	char				**arg;
	char				*str;
	void				*buf;
	int					l1;
	int					l2;
	int					l3;
	int					l4;
	int					l5;
	ptrdiff_t			j1;
	ptrdiff_t			j2;
	ptrdiff_t			j3;
	unsigned long long	j4;
	ptrdiff_t			j5;
	unsigned long long	j6;
	int					data;
	wchar_t				*wchar;
	char				*tmp1;
	char				*tmp2;
}						t_arg;

/*
**	int			hh;  флаг размера
**	int			h; флаг размера
**	int			l; флаг размера
**	int			ll; флаг размера
**	int			j; флаг размера
**	int			z; флаг размера
**	int			t; флаг размера
**	int			L; флаг размера
**	int			re; сколько символов напечатано
**	int			accuracy; точность
**	int			width; ширина
**	int			minus; флаг
**	int			plus; флаг
**	int			spase; флаг
**	int			hash; флаг
**	int			zero; флаг
**	char		**arg; условия, которые зашли, const char *format,
**	char		*str; буфер для записи вывода на экран
**	void		*buf; буфер для получения данных из va_list args
**	int			l1; счетчик 1
**	int			l2; счетчик 2
**	int			l3; счетчик 3
**	int			l4; счетчик 4
**	int			data; тип данных.
*/

int						ft_printf(const char *format, ...);
void					ft_printf_take_args(const char *format, va_list args,
						t_arg *s);
void					ft_printf_read_format(char *f, va_list args,
						t_arg *s);
void					ft_printf_write_data(char *f, t_arg *s);
int						ft_printf_flags(char f, t_arg *s);
void					ft_printf_accuracy(char *f, t_arg *s,
						va_list args);
void					ft_printf_width(char *f, t_arg *s, va_list args);
int						ft_printf_mods(char *f, t_arg *s);
int						ft_printf_data_type(char f, va_list args, t_arg *s);
int						ft_printf_data_type2(char f);
t_arg					*ft_printf_make_mem(void);
void					ft_printf_clear_t_arg(t_arg *s);
void					ft_printf_clear_t_arg2(t_arg *s);
void					ft_printf_del_arg(t_arg *del);
int						how_m_words(char const *str);
int						how_b(char const *str, int i);
char					**ft_printf_split_format(char const *f, int i, int args,
						int a);
char					*ft_printf_prs(char *f, t_arg *s);
char					*ft_printf_prs2(char *f, t_arg *s);
void					ft_printf_nonf(char *f, t_arg *s);
void					ft_printf_nonf2(t_arg *s, char t);
void					ft_printf_data_s(t_arg *s);
void					ft_printf_data_ss(char p, t_arg *s);
void					ft_printf_data_width(t_arg *s, char t);
void					ft_printf_data_width_c(t_arg *s, char t);
void					ft_printf_data_print(t_arg *s);
void					ft_printf_data_s_wchar_t(t_arg *s);
void					ft_printf_data_wchar_read(t_arg *s);
void					ft_printf_data_wchar_read2(t_arg *s);
void					ft_printf_data_wchar_width(t_arg *s, char t);
char					*ft_printf_wchar_decode(int t, t_arg *s, int z);
void					ft_printf_data_c(t_arg *s);
void					ft_printf_data_c2(t_arg *s);
void					ft_printf_data_c_wchar_t(t_arg *s);
void					ft_printf_data_d(t_arg *s);
void					ft_printf_data_d2(t_arg *s);
void					ft_printf_data_d3(t_arg *s);
void					ft_printf_data_ps(t_arg *s);
void					ft_printf_data_u(t_arg *s);
void					ft_printf_data_o(t_arg *s);
void					ft_printf_data_o2(t_arg *s);
void					ft_printf_data_x(t_arg *s);
char					*ft_printf_itoa(t_arg *s, int base, int minf);
char					*ft_printf_itoa_unsigned(t_arg *s, int base, int minf);
t_arg					*ft_printf_flags_unsigned(t_arg *s);
int						ft_printf_itoa_unsignedlen(t_arg *s, int b);
char					*ft_printf_itoa_unsigmake(t_arg *s, char *r, int minf,
						int base);
void					ft_printf_data_0x(t_arg *s);
t_arg					*ft_printf_flags_signed(t_arg *s);
char					*ft_printf_itoa_make(t_arg *s, char *r, int minf,
						int base);
char					*ft_printf_itoa_rev(char *src, char *dst, t_arg *s,
						int min);
int						ft_printf_itoa_len(t_arg *s, int b);
char					ft_printf_itoa_hash(int base, t_arg *s);
void					ft_printf_data_p(t_arg *s);
int						ft_printf_chek_data(char f);

#endif
