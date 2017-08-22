/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_data_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 16:58:34 by dverbyts          #+#    #+#             */
/*   Updated: 2017/08/08 16:58:37 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_data_s(t_arg *s)
{
	if (s->l == 1 || s->data == 'S')
		return (ft_printf_data_s_wchar_t(s));
	else
	{
		if (s->buf != NULL)
		{
			s->str = ft_strnew(ft_strlen((char *)s->buf));
			s->str = ft_strcpy(s->str, (char *)s->buf);
		}
		else
		{
			s->str = ft_strnew(7);
			s->str = "(null)\0";
		}
	}
	if (s->accuracy > -1 && s->accuracy < (int)ft_strlen(s->str))
		s->str[s->accuracy] = '\0';
	if (s->width > 0 && s->width > (int)ft_strlen(s->str))
	{	
		if (s->zero == 1)
			return (ft_printf_data_width(s, '0'));
		else
			return (ft_printf_data_width(s, ' '));
	}
	return (ft_printf_data_print(s));
}

void	ft_printf_data_width(t_arg *s, char t)
{
	char *tmp;

	s->l3 = (int)ft_strlen(s->str);
	s->l4 = s->width - s->l3;
	tmp = ft_strnew(s->l3 + s->l4);
	if (s->minus == 1)
	{
		while (s->l5 < s->width)
			tmp[s->l5] = s->str[s->l5++];
		while (s->l5 < (s->l3 + s->l4))
			tmp[s->l5++] = t;
	}
	else
	{
		while (s->l5 < s->width)
			tmp[s->l5++] = t;
		while (s->l5 < (s->l3 + s->l4))
			tmp[s->l5] = s->str[s->l5++];
	}
	tmp[s->l5] = '\0';
	free(s->str);
	s->str = tmp;
	return ;
}

void	ft_printf_data_print(t_arg *s)
{
	s->l5 = 0;
	while(s->str[s->l5])
		write(1, &s->str[s->l5++], 1);
	return ;
}
