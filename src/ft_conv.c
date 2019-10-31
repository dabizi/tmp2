/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:53:23 by jgrandne          #+#    #+#             */
/*   Updated: 2019/10/31 15:39:21 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_out(char *str, int *res, t_printf *t_flag)
{
	int i;

	i = 0;
	while (t_flag->width != 0 && str[i])
	{
		ft_putchar_fd(str[i], 1);
		*res += 1;
		t_flag->width -= 1;
		i++;
	}
}

void	ft_conv_char(va_list aux, int *res, t_printf *t_flag)
{
	char c;

	t_flag->conv = 0;
	c = va_arg(aux, int);
	*res += 1;
	ft_putchar_fd(c, 1);
}

void	ft_conv_str(va_list aux, int *res, t_printf *t_flag)
{
	char *str;

	t_flag->conv = 0;
	str = va_arg(aux, char*);
	if (str)
		ft_out(str, res, t_flag);
	else
		ft_out("(null)", res, t_flag);
}

void	ft_space(int nb, int cas, int *res, t_printf *t_flag)
{
	while (nb > 0)
	{
		if (cas)
		{
			ft_putchar_fd('0', 1);
			t_flag->width -= 1;
		}
		else
		{
			ft_putchar_fd(' ', 1);
			t_flag->width -= 1;
		}
		*res += 1;
		nb--;
	}
}

void	ft_update(t_printf *t_flag, int size, int *res)
{
	if (t_flag->width > size)
		ft_space(t_flag->width - size, 1, res, t_flag);
	else if (t_flag->percent > size)
		ft_space(t_flag->percent - size, 1, res, t_flag);
	if (t_flag->space_before > 0)
		ft_space(t_flag->space_before - size, t_flag->zero, res, t_flag);
}

void	ft_conv_int(va_list aux, int *res, t_printf *t_flag)
{
	int nb;

	t_flag->conv = 0;
	nb = va_arg(aux, int);
	ft_update(t_flag, ft_strlen(ft_itoa(nb)), res);
	if (t_flag->zero > 0 && nb < 0)
	{
		nb = -nb;
		ft_putchar_fd('-', 1);
		*res += 1;
		t_flag->width = t_flag->width - 1;
	}
	if (t_flag->fl_poi && nb == 0)
		return;
	ft_putnbr_fd(nb, 1);
	*res += ft_strlen(ft_itoa(nb));
}

void	ft_conv_uint(va_list aux, int *res, t_printf *t_flag)
{
	unsigned int nb;

	t_flag->conv = 0;
	nb = va_arg(aux, unsigned int);
	if (t_flag->fl_poi && nb == 0)
		return;
	ft_update(t_flag, ft_strlen(ft_itoa(nb)), res);
	ft_putnbru_fd(nb, 1);
	*res += ft_strlen(ft_itoau(nb));
}

void	ft_conv_adr(va_list aux, int *res, int cse, t_printf *t_flag)
{
	long long ptr;
	char *tmp;

	t_flag->conv = 0;
	(cse == 1) ? ft_putstr_fd("0x", 1) : 0;
	if (cse == 1)
	{
		*res += 2;
		ptr = va_arg(aux, long long);
	}
	else
		ptr = va_arg(aux, unsigned int);
	if (t_flag->fl_poi && ptr == 0)
		return;
	ft_update(t_flag, ft_strlen(ft_itoa(ptr)), res);
	tmp = (cse == 2) ? ft_itoa_base(ptr, CAP) : ft_itoa_base(ptr, MIN);
	ft_putstr_fd(tmp, 1);
	*res += ft_strlen(tmp);
	free(tmp);
}
