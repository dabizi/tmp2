/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:53:23 by jgrandne          #+#    #+#             */
/*   Updated: 2019/10/25 19:13:05 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_conv_char(va_list aux, int *res)
{
	char c;

	c = va_arg(aux, int);
	*res += 1;
	ft_putchar_fd(c, 1);
}

void	ft_conv_str(va_list aux, int *res)
{
	char *str;

	str = va_arg(aux, char*);
	if (str != NULL)
	{
		ft_putstr_fd(str, 1);
		*res += ft_strlen(str);
	}
	else
	{
		*res += 6;
		write(1, "(null)", 6);
	}
}

void	ft_conv_int(va_list aux, int *res)
{
	int nb;

	nb = va_arg(aux, int);
	ft_putnbr_fd(nb, 1);
	*res += ft_strlen(ft_itoa(nb));
}

void	ft_conv_uint(va_list aux, int *res)
{
	unsigned int nb;

	nb = va_arg(aux, unsigned int);
	ft_putnbru_fd(nb, 1);
	*res += ft_strlen(ft_itoau(nb));
}

void	ft_conv_adr(va_list aux, int *res, int cse)
{
	long long ptr;
	char *tmp;

	(cse == 1) ? ft_putstr_fd("0x", 1) : 0;
	if (cse == 1)
		*res += 2;
	ptr = va_arg(aux, long long);
	tmp = (cse < 3) ? ft_itoa_base(ptr, CAP) : ft_itoa_base(ptr, MIN);
	ft_putstr_fd(tmp, 1);
	*res += ft_strlen(tmp);
	free(tmp);
}
