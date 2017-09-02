/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_non_format.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 17:13:38 by dverbyts          #+#    #+#             */
/*   Updated: 2017/08/05 17:13:39 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_prs(char const f, t_arg *s)
{
	char *r;

	r = ft_strnew(2);
	r[0] = f;
	r[1] = '\0';
	if (s->buf == NULL)
		s->buf = r;
	else
		s->buf = ft_strjoin(r, (char *)s->buf);
	s->accuracy = 1;
}
