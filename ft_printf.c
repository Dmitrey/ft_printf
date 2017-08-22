/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 17:04:16 by dverbyts          #+#    #+#             */
/*   Updated: 2017/08/01 17:04:17 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		sum;
	va_list	args;
	t_arg	*s;

	sum = 0;
	va_start(args, format);
	s = ft_printf_make_mem();
	ft_printf_take_args(format, args, s);
	sum = s->re;
	ft_printf_del_arg(s);
	va_end(args);
	return (sum);
}

int		ft_printf_take_args(char const *format, va_list args, t_arg *s)
{
	s->l1 = 0;
	while (format[s->l1] != '%' && format[s->l1] != '\0')
	{
		write(1, &format[s->l1++], 1);
		s->re++;
	}
	s->arg = ft_printf_split_format(format, 0, 0, s->l1);
	s->l1 = 0;
	while (s->arg[s->l1] != NULL)
		ft_printf_read_format(s->arg[s->l1++], args, s);
	return (s->re);
}

void	ft_printf_read_format(char const *f, va_list args, t_arg *s)
{
	ft_printf_clear_t_arg(s);
	while (f[s->l2] != '\0')
	{
		if (f[s->l2] == '%' && f[s->l2 + 1] == '%')
			ft_printf_percent(f, s);
		else if (ft_printf_flags(f[s->l2], s) == 1)
			s->l2++;
		else if (f[s->l2] == '.')
			ft_printf_accuracy(f, s, args);
		else if (f[s->l2] == '*' || ft_isdigit(f[s->l2]) == 1)
			ft_printf_width(f, s, args);
		else if (ft_printf_mods(f, s) == 1)
			s->l2++;
		else if (ft_printf_data_type(f[s->l2], args, s) == 1)
		{
			ft_printf_write_data(f, s);
			while (f[++s->l2] != '\0')
				write(1, &f[s->l2], 1);
			break ;
		}
		else if (f[s->l2] == '%')
			s->l2++;
	}
	return ;
}

void	ft_printf_write_data(char const *f, t_arg *s)
{
	if (s->data == 's' || s->data == 'S')
		ft_printf_data_s(s);
	else if (s->data == 'p')
		ft_printf_data_p(s);
	else if (s->data == 'd' || s->data == 'D' || s->data == 'i')
		ft_printf_data_d(s);
	else if (s->data == 'o' || s->data == 'O')
		ft_printf_data_o(s);
	else if (s->data == 'u' || s->data == 'U')
		ft_printf_data_u(s);
	else if (s->data == 'x' || s->data == 'X')
		ft_printf_data_x(s);
	else if (s->data == 'c' || s->data == 'C')
		ft_printf_data_c(s);
//	else if (s->data == 'n')
//		ft_printf_data_n(f, s);
	while (f[s->l2] != '\0')
	{
		write(1, &f[s->l2++], 1);
		s->re++;
	}
	return ;
}
