/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_parsing.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 17:41:14 by dverbyts          #+#    #+#             */
/*   Updated: 2017/08/05 17:41:15 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_flags(char f, t_arg *s)
{
	if (f == '-')
		return (s->minus = 1);
	else if (f == '+')
		return (s->plus = 1);
	else if (f == ' ')
		return (s->spase = 1);
	else if (f == '#')
		return (s->hash = 1);
	else if (f == '0')
		return (s->zero = 1);
	return (0);
}

void	ft_printf_accuracy(char const *f, t_arg *s, va_list args)
{
	if (f[s->l2] == '.')
		s->l2++;
	if (f[s->l2] == '*')
	{
		s->accuracy = va_arg(args, int);
		s->l2++;
	}
	else if (ft_isdigit(f[s->l2]) == 1)
	{
		s->accuracy = 0;
		while (ft_isdigit(f[s->l2]) == 1)
			s->accuracy = s->accuracy * 10 + (f[s->l2++] - '0');
	}
	if (s->accuracy == -1)
		s->accuracy = 0;
	return ;
}

void	ft_printf_width(char const *f, t_arg *s, va_list args)
{
	if (f[s->l2] == '*')
	{
		s->width = va_arg(args, int);
		s->l2++;
	}
	else if (ft_isdigit(f[s->l2]) == 1)
		while (ft_isdigit(f[s->l2]) == 1)
			s->width = s->width * 10 + (f[s->l2++] - '0');
	if (s->width < 0)
	{
		s->minus = 1;
		s->width *= -1;
	}
	return ;
}

int		ft_printf_mods(char const *f, t_arg *s)
{
	if (f[s->l2] == 'h' && s->h != 1)
		return (s->h = 1);
	else if (f[s->l2] == 'h' && s->h == 1)
	{
		s->h = 0;
		return (s->hh = 1);
	}
	else if (f[s->l2] == 'l' && s->l != 1)
		return (s->l = 1);
	else if (f[s->l2] == 'l' && s->l == 1)
	{
		s->l = 0;
		return (s->ll = 1);
	}
	else if (f[s->l2] == 'L')
		return (s->L = 1);
	else if (f[s->l2] == 'j')
		return (s->j = 1);
	else if (f[s->l2] == 'z')
		return (s->z = 1);
	else if (f[s->l2] == 't')
		return (s->t = 1);
	return (0);
}

int		ft_printf_data_type(char f, va_list args, t_arg *s)
{
	char *buf2;

	if (f == 's' || f == 'S' || f == 'p' || f == 'd' || f == 'D' || f == 'i'
		|| f == 'o' || f == 'O' || f == 'u' || f == 'U' || f == 'x' || f == 'X'
		|| f == 'c' || f == 'C' || f == 'n')
	{
		s->data = (int)f;
		if (s->buf == NULL)
			s->buf = va_arg(args, void *);
		else
		{
			buf2 = va_arg(args, void *);
			s->buf = ft_strjoin((char *)s->buf, buf2);
		}
		s->l2++;
		return (1);
	}
	return (0);
}
