/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:18:01 by jgrandne          #+#    #+#             */
/*   Updated: 2019/10/30 18:49:13 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_conv_per(int *res)
{
	ft_putchar_fd('%', 1);
}

void	ft_flags_m(va_list aux, int *res, t_printf *t_flag)
{
	t_flag->minus = 1;
}

void	ft_flags_z(va_list aux, int *res, t_printf *t_flag)
{
	t_flag->zero = 1;
}

void	ft_flags_p(va_list aux, int *res, t_printf *t_flag)
{
	t_flag->width = 0;
}

void	ft_flags_s(va_list aux, int *res, t_printf *t_flag)
{
	t_flag->space = va_arg(aux, int);
}

void	ft_flags_n(char *str, t_printf *t_flag)
{
	if (t_flag->space == 0)
		t_flag->space = ft_atoi(str);
	if (t_flag->width == 0)
		t_flag->width = ft_atoi(str);
}
