/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_make_mem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 17:29:11 by dverbyts          #+#    #+#             */
/*   Updated: 2017/08/01 17:29:13 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg	*ft_printf_make_mem(void)
{
	t_arg *ret;

	if (!(ret = (t_arg *)malloc(sizeof(t_arg))))
		return (0);
	ft_bzero(ret, sizeof(t_arg));
	ret->accuracy = -1;
	return (ret);
}

void	ft_printf_clear_t_arg(t_arg *x)
{
	x->hh = 0;
	x->h = 0;
	x->l = 0;
	x->ll = 0;
	x->j = 0;
	x->z = 0;
	x->t = 0;
	x->L = 0;
	x->accuracy = -1;
	x->width = 0;
	x->minus = 0;
	x->plus = 0;
	x->spase = 0;
	x->hash = 0;
	x->zero = 0;
	x->l1 = 0;
	x->l2 = 0;
	x->l3 = 0;
	x->l4 = 0;
	x->l5 = 0;
	x->data = 0;
	return ;
}

void	ft_printf_del_arg(t_arg *del)
{
	int l;

	l = 0;
	if (del != NULL)
	{
		ft_bzero(del, sizeof(t_arg));
		while (del->arg[l])
			free(del->arg[l++]);
		free(del->arg);
		free(del);
	}
	return ;
}
