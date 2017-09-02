/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_data_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 21:15:13 by dverbyts          #+#    #+#             */
/*   Updated: 2017/08/15 21:15:15 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_data_c(t_arg *s)
{
	char r;

	if (s->l == 1 || s->data == 'C')
		return (ft_printf_data_c_wchar_t(s));
	else
	{
		s->str = ft_strnew(1);
		if (s->buf != NULL)
		{
			r = (char)s->buf;
			s->str[0] = r;
		}
		else
			s->str[0] = '\0';
	}
	if (s->width > 1)
	{	
		if (s->zero == 1)
			return (ft_printf_data_width_c(s, '0'));
		else
			return (ft_printf_data_width_c(s, ' '));
	}
	return ;
}

void	ft_printf_data_c_wchar_t(t_arg *s)
{
	wchar_t wchar;

	s->str = ft_strnew(1);
	if (s->buf != NULL)
	{
		wchar = (wchar_t) s->buf;
		if ((int)wchar < 128)
			s->str[0] = (char) wchar;
		else
			s->str = ft_printf_data_wchar_decode((int) wchar, s, 0);
	}
	else
		s->str = "\0";
	if (s->width > 1) 
	{
		if (s->zero == 1)
			return (ft_printf_data_wchar_width(s, '0'));
		else
			return (ft_printf_data_wchar_width(s, ' '));
	}
	return ;
}

void	ft_printf_data_width_c(t_arg *s, char t)
{
	char *tmp;

	s->l1 = 0;
	s->l3 = (int)ft_strlen(s->str);
	s->l4 = s->width - s->l3 - (s->buf == NULL ? 1 : 0);
	tmp = ft_strnew(s->l3 + s->l4);
	if (s->minus == 1)
	{
		while (s->l5 < s->l4 && s->str[s->l1] != '\0')
			tmp[s->l5++] = s->str[s->l1++];
		while (s->l5 < (s->l3 + s->l4))
			tmp[s->l5++] = t;
	}
	else
	{
		while (s->l5 < s->l4)
			tmp[s->l5++] = t;
		while (s->l5 < (s->l3 + s->l4) && s->str[s->l1] != '\0')
			tmp[s->l5++] = s->str[s->l1++];
	}
	tmp[s->l5] = '\0';
	free(s->str);
	s->str = tmp;
	return ;
}
