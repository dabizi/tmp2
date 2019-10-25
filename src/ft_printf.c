/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:10:07 by jgrandne          #+#    #+#             */
/*   Updated: 2019/10/25 17:57:03 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int					ft_printf(const char *str, ...)
{
	va_list		aux;
	int			i;
	int			res;

	i = 0;
	res = 0;
	va_start(aux, str);
	while (str[i])
	{
		if (str[i] == '%')
			ft_parse_conv(&i, str, aux, &res);
		else
			ft_putchar_fd(str[i], 1);
	}
	va_end(aux);
	return (res);
}
