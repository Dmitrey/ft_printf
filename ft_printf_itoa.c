/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 17:27:38 by dverbyts          #+#    #+#             */
/*   Updated: 2017/08/20 17:27:40 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_printf_itoa_hash(int base, t_arg *s)
{

	if (s->j5 % base == 10)
		return (s->data > 96 ? 'a' : 'A');
	else if (s->j5 % base == 11)
		return (s->data > 96 ? 'b' : 'B');
	else if (s->j5 % base == 12)
		return (s->data > 96 ? 'c' : 'C');
	else if (s->j5 % base == 13)
		return (s->data > 96 ? 'd' : 'D');
	else if (s->j5 % base == 14)
		return (s->data > 96 ? 'e' : 'E');
	else if (s->j5 % base == 15)
		return (s->data > 96 ? 'f' : 'F');
	return ('0');
}

unsigned long long int	ft_printf_itoa_len(t_arg *s)
{
	unsigned long long int	len;
	unsigned long long int	n;

	n = s->j1;
	len = 1;
	if ((ptrdiff_t)s->buf < 0)
	{
		n = n * -1;
		len++;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_printf_itoa_rev(char *src, char *dst, t_arg *s, int min)
{
	size_t count;

	--s->j2;
	count = ft_strlen(src) - 1;
	s->j1 = 0;
	if (min == 1)
	{
		dst[s->j1] = '-';
		s->j1++;
		s->j2--;
	}
	while (s->j2)
	{
		dst[s->j1++] = src[count--];
		s->j2--;
	}
	if (src[0] == 0)
		dst[0] = '0';
	dst[s->j1] = '\0';
	return (dst);
}

char			*ft_printf_itoa_make(t_arg *s, char *r, int minf, int base)
{
	char	*buf;

	s->j3 = s->j2 - 1;
	if (!(buf = (char *)malloc(sizeof(char) * s->j2)))
		return (0);
	if (minf == 1)
	{
		s->j5 = s->j5 * -1;
		s->j3--;
	}
	while ((unsigned long long)s->l5 < s->j3)
	{
		if (s->j5 % base < 10)
			buf[s->l5++] = s->j5 % base + '0';
		else
			buf[s->l5++] = ft_printf_itoa_hash(base, s);
		s->j5 = s->j5 / base;
	}
	buf[s->l5] = '\0';
	r = ft_printf_itoa_rev(buf, r, s, minf);
	if (!buf)
		return (r);
	free(buf);
	return (r);
}

char			*ft_printf_itoa(t_arg *s, int base)
{
	char					*re;
	int 					minf;

	minf = 0;
	s->l5 = 0;
	s->j1 = (ptrdiff_t)s->buf;
	s->j5 = (ptrdiff_t)s->buf;
	if ((ptrdiff_t)s->buf < 0)
		minf = 1;
	s->j2 = ft_printf_itoa_len(s);
	if (!(re = (char *)malloc(sizeof(char) * s->j2)))
		return (0);
	s->str = ft_printf_itoa_make(s, re, minf, base);
	return (re);
}
