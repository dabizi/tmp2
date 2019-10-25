/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:53:23 by jgrandne          #+#    #+#             */
/*   Updated: 2019/10/25 16:56:28 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int			ft_printnbru(va_list aux)
{
	unsigned int nb;

	nb = va_arg(aux, unsigned int);
	ft_putnbru_fd(nb, 1);
	return (ft_strlen(ft_itoau(nb)));
}

int			ft_printptr(va_list aux, int cse)
{
	long long ptr;
	char *tmp;
	int			len;

	if (cse == 1)
		ft_putstr_fd("0x", 1);
	ptr = va_arg(aux, long long);
	if (cse == 1 || cse == 2)
		tmp = ft_itoa_base(ptr, MIN);
	else
		tmp = ft_itoa_base(ptr, CAP);
	if (cse != 1)
		ft_putstr_fd(tmp + 4, 1);
	else
		ft_putstr_fd(tmp, 1);
	len = ft_strlen(tmp);
	free(tmp);
	return (len + ((cse == 1) ? 2 : -4));
}
