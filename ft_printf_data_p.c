/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_data_p.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 17:20:06 by dverbyts          #+#    #+#             */
/*   Updated: 2017/08/22 17:20:08 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_data_p(t_arg *s)
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
