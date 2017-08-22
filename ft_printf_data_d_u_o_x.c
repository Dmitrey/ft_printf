/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_data_d_u_o_x.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 14:26:52 by dverbyts          #+#    #+#             */
/*   Updated: 2017/08/20 14:26:53 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_data_d(t_arg *s)
{
	if (s->t == 1 || s->z == 1 || s->j == 1 || s->ll == 1 || s->h == 1 ||
		s->hh == 1 || s->l == 1)
		s->str = ft_printf_itoa(s, 10);
	else
		s->str = ft_itoa((int)s->buf);
	if ((ptrdiff_t)s->buf == 0 && s->accuracy == 0)
	{
		s->str[0] = '\0';
		return ;
	}
	if (s->plus == 1 || s->spase == 1)
		ft_printf_data_d_ps(s);
	if (s->width > 0 && s->width > (int)ft_strlen(s->str))
	{
		if (s->zero == 1)
			return (ft_printf_data_width(s, '0'));
		else
			return (ft_printf_data_width(s, ' '));
	}
	return (ft_printf_data_print(s));
}

void	ft_printf_data_d_ps(t_arg *s)
{
	char t[2];

	t[0] = '\0';
	t[1] = '\0';
	if (s->spase == 1)
		t[0] = ' ';
	if (s->plus == 1)
	{
		if ((ptrdiff_t)s->buf < 0 && s->str[0] != '-')
			t[0] = '-';
		else
			t[0] = '+';
	}
	s->str = ft_strjoin(t, s->str);
	return ;
}

void	ft_printf_data_u(t_arg *s)
{
	if (s->t == 1 || s->z == 1 || s->j == 1 || s->ll == 1 || s->h == 1 ||
		s->hh == 1 || s->l == 1)
		s->str = ft_printf_itoa(s, 10);
	else
		s->str = ft_itoa((int)s->buf);
	if ((ptrdiff_t)s->buf == 0 && s->accuracy == 0)
	{
		s->str[0] = '\0';
		return ;
	}
	if (s->plus == 1)
		s->plus = 0;
	if (s->spase == 1)
		ft_printf_data_d_ps(s);
	if (s->width > 0 && s->width > (int)ft_strlen(s->str))
	{
		if (s->zero == 1)
			return (ft_printf_data_width(s, '0'));
		else
			return (ft_printf_data_width(s, ' '));
	}
	return (ft_printf_data_print(s));
}

void	ft_printf_data_o(t_arg *s)
{
	s->str = ft_printf_itoa(s, 8);
	if ((ptrdiff_t)s->buf == 0 && s->accuracy == 0)
	{
		s->str[0] = '\0';
		return ;
	}
	if (s->plus == 1)
		s->plus = 0;
	if (s->spase == 1)
		ft_printf_data_d_ps(s);
	if (s->width > 0 && s->width > (int)ft_strlen(s->str))
	{
		if (s->zero == 1)
			return (ft_printf_data_width(s, '0'));
		else
			return (ft_printf_data_width(s, ' '));
	}
	return (ft_printf_data_print(s));
}

void	ft_printf_data_x(t_arg *s)
{
	s->str = ft_printf_itoa(s, 15);
	if ((ptrdiff_t)s->buf == 0 && s->accuracy == 0)
	{
		s->str[0] = '\0';
		return ;
	}
	if (s->plus == 1)
		s->plus = 0;
	if (s->spase == 1)
		ft_printf_data_d_ps(s);
	if (s->width > 0 && s->width > (int)ft_strlen(s->str))
	{
		if (s->zero == 1)
			return (ft_printf_data_width(s, '0'));
		else
			return (ft_printf_data_width(s, ' '));
	}
	return (ft_printf_data_print(s));
}
