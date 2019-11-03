/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:10:07 by jgrandne          #+#    #+#             */
/*   Updated: 2019/11/03 18:50:16 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"


int					ft_printf(const char *str, ...)
{
	va_list		aux;
	int			i;
	int			res;
	t_printf	*t_flag;

	i = 0;
	res = 0;
	va_start(aux, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			t_flag = ft_parse_conv(&i, str, aux, &res);
			i -= 1;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			res += 1;
		}
		i++;
	}
	va_end(aux);
	return (res);
}
