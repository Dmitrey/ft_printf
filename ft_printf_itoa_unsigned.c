/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 19:04:49 by dverbyts          #+#    #+#             */
/*   Updated: 2017/08/31 19:04:53 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_printf_itoa_unsigned(t_arg *s, int base, int minf)
{
	char					*re;

	s->l5 = 0;
	s = ft_printf_flags_unsigned(s);
	s->j5 = s->j1;
	if (s->j1 == 0)
	{
		re = ft_strnew(2);
        re[0] = '0';
        re[1] = '\0';
		return (re);
	}
	s->j2 = ft_printf_itoa_unsignedlen(s, base);
	if (!(re = (char *)malloc(sizeof(char) * s->j2)))
		return (0);
	s->str = ft_printf_itoa_make(s, re, minf, base);
	return (re);
}

t_arg		*ft_printf_flags_unsigned(t_arg *s)
{
	if (s->hh == 1)
		s->j1 = (unsigned char)s->buf;
	else if (s->h == 1)
		s->j1 = (unsigned short)s->buf;
	else if (s->l == 1)
		s->j1 = (unsigned long)s->buf;
	else if (s->ll == 1)
		s->j1 = (unsigned long long)s->buf;
	else if (s->j == 1)
		s->j1 = (uintmax_t)s->buf;
	else if (s->z == 1)
		s->j1 = (size_t)s->buf;
	else if (s->t == 1)
		s->j1 = (ptrdiff_t)s->buf;
	else 
		s->j1 = (unsigned int)s->buf;
	return (s);
}

t_arg		*ft_printf_flags_signed(t_arg *s)
{
	if (s->hh == 1)
		s->j1 = (signed char)s->buf;
	else if (s->h == 1)
		s->j1 = (short)s->buf;
	else if (s->l == 1)
		s->j1 = (long)s->buf;
	else if (s->ll == 1)
		s->j1 = (long long)s->buf;
	else if (s->j == 1)
		s->j1 = (intmax_t)s->buf;
	else if (s->z == 1)
		s->j1 = (size_t)s->buf;
	else if (s->t == 1)
		s->j1 = (ptrdiff_t)s->buf;
	else 
		s->j1 = (int)s->buf;
	return (s);
}

unsigned long long int	ft_printf_itoa_unsignedlen(t_arg *s, int b)
{
	unsigned long long int	len;
	unsigned long long int	n;

	n = s->j1;
	len = 1;
	while (n != 0)
	{
		n = n / b;
		len++;
	}
	return (len);
}
