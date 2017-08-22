/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_split_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 21:12:58 by dverbyts          #+#    #+#             */
/*   Updated: 2017/08/01 21:13:00 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		how_m_words(char const *str)
{
	int words;
	int i;

	words = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '%')
			words++;
		i++;
	}
	return (words);
}

int		how_b(char const *str, int i)
{
	int counter;

	counter = 1;
	while (str[i] == '%' && str[i++] != '\0')
		counter++;
	while (str[i] != '%' && str[i++] != '\0')
		counter++;
	return (counter);
}

char			**ft_printf_split_format(char const *f, int i, int args, int a)
{
	char	**array;
	int		l;
	int		arg;

	if (!f)
		return (NULL);
	args = how_m_words(f);
	if (!(array = (char **)malloc(sizeof(char *) * args)))
		return (NULL);
	ft_bzero(array, sizeof(char *) * args);
	while (f[a] != '\0')
	{
		arg = how_b(f, a);
		l = 0;
		if (!(array[i] = (char *)malloc(sizeof(char) * arg)))
			return (NULL);
		ft_bzero(array[i], sizeof(char) * arg);
		while (f[a] == '%' && f[a] != '\0')
			array[i][l++] = f[a++];
		while (f[a] != '%' && f[a] != '\0')
			array[i][l++] = f[a++];
		array[i++][l] = '\0';
	}
	array[i] = NULL;
	return (array);
}
