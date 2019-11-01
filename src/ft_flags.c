/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:18:01 by jgrandne          #+#    #+#             */
/*   Updated: 2019/11/01 19:20:26 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_conv_per(int *res, t_printf *t_flag)
{
	t_flag->conv = 0;
	//printf("percent vaut %d\n", t_flag->percent);
	ft_space(t_flag->percent - 1, 1, res, t_flag);
	ft_putchar_fd('%', 1);
}

void	ft_flags_m(va_list aux, int *res, t_printf *t_flag)
{
	t_flag->fl_min = 1;
}

void	ft_flags_z(va_list aux, int *res, t_printf *t_flag, int *i)
{
//	if (t_flag->width != 0)
		t_flag->zero = 1;
//	else
//		t_flag->width = -1;
	*i += 1;
}

void	ft_flags_p(va_list aux, int *res, t_printf *t_flag)
{
	t_flag->fl_poi = 1;
}

void	ft_flags_s(va_list aux, int *res, t_printf *t_flag)
{
	if (!t_flag->fl_sta)
	{
		t_flag->fl_sta = 1;
		t_flag->space_before = va_arg(aux, int);
	} else
	{
		t_flag->space_after = va_arg(aux, int);

	}
}

void	ft_flags_n(char *str, t_printf *t_flag, int *i)
{
	if (t_flag->width == -1)
	{
		if (ft_atoi(str) > 1)
			t_flag->width = ft_atoi(str);
	}
	else if (t_flag->fl_poi)
	{
		if (ft_atoi(str) > 1)
				t_flag->size = ft_atoi(str);
	}
	if (ft_atoi(str) > 1)
		t_flag->percent = ft_atoi(str);
	*i += ft_strlen(ft_itoa(ft_atoi(str)));
/*
	if (t_flag->width == 0)
	{
		if (ft_atoi(str) > 1)
			t_flag->width = ft_atoi(str);
		else
			t_flag->width = -1;
	}
	t_flag->percent = ft_atoi(str);
	*/
//	printf("Percent vaut %d\n", t_flag->percent);
//	printf("Width vaut %d\n", t_flag->width);
//	printf("Zero vaut %d\n", t_flag->zero);
}
