/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:10:07 by jgrandne          #+#    #+#             */
/*   Updated: 2019/10/23 17:55:08 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "../inc/ft_printf.h"

int				ft_printchar(va_list aux)
{
	int c;

	c = va_arg(aux, int);
	ft_putchar_fd(c, 1);
	return (1);
}


int				ft_printstr(va_list aux)
{
	char *str;

	str = va_arg(aux, char *);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int			ft_printnbr(va_list aux)
{
	int nb;

	nb = va_arg(aux, int);
	ft_putnbr_fd(nb, 1);
	return (ft_strlen(ft_itoa(nb)));
}

int			ft_printptr(va_list aux)
{
	long long ptr;

	char hex[16] = "0123456789abcdef";
	char Hex[16] = "0123456789ABCDEF";

	ft_putstr_fd("0x", 1);
	ptr = va_arg(aux, long long);
	while (ptr > 16)
	{
		ft_putchar_fd(hex[ptr % 16], 1);
		ptr /= 16;
	}
	ft_putchar_fd(hex[ptr], 1);
	return (ft_strlen(ft_itoa(ptr)));
}

static int			ft_switch(char c, va_list aux)
{
	int nb;
//	d = va_arg(aux, int)
//	va_copy();

	nb = 0;
	if (c =='c')
		nb += ft_printchar(aux);
	else if (c == 's')
		nb += ft_printstr(aux);
	else if (c == 'p')
		nb += ft_printptr(aux);
	else if (c == 'd')
		nb += ft_printnbr(aux);
	else if (c == 'i')
		nb += ft_printnbr(aux);
	else if (c == 'u')
		ft_putchar_fd('u', 1);
	else if (c == 'x')
		ft_putchar_fd('x', 1);
	else if (c == 'X')
		ft_putchar_fd('X', 1);
	else if (c == '%')
		ft_putchar_fd('%', 1);
	else
		return (-1);
	return (nb);
}

int					ft_printf(const char *str, ...)
{
	va_list		aux;
	int			end;
	int			i;
	t_list		t_flags;
	int			res;

	res = 0;
	i = 0;
	end = 0;
	va_start(aux, str);
	while (!end && str[i])
	{
		if (str[i] == '%')
		{
			res += ft_switch(str[i + 1], aux);
			i += 2;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			i++;
			res++;
		}
	}
	va_end(aux);
	return (res);
}
