/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_addr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:37:03 by jgrandne          #+#    #+#             */
/*   Updated: 2019/10/31 18:36:21 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"


void	ft_handle_spaceadd(int *res, t_printf *t_flag, int size)
{

//	printf("Siz vaut : %d\n", t_flag->size);
//	printf("Width vaut : %d\n", t_flag->width);
//	printf("Sta vaut : %d\n", t_flag->fl_sta);
//	printf("Space vaut : %d\n", t_flag->space_before);

	if (t_flag->fl_sta)
	{
		ft_space(t_flag->space_before - size, t_flag->zero, res, t_flag);
	
	}

	if (t_flag->width < 0)
		return ;
	if (t_flag->width > 0 && t_flag->size == -1)
	{
	//	printf("size : %d\n", size);
		ft_space(t_flag->width - size, !t_flag->zero, res, t_flag);
		return ;
	}
	if (t_flag->width > 0 && t_flag->size > -1)
	{
		ft_space(t_flag->width - t_flag->size, !t_flag->zero, res, t_flag);
		return ;
	}
}



void	ft_conv_padr(va_list aux, int *res, t_printf *t_flag)
{
	long long ptr;
	char *tmp;

	t_flag->conv = 0;
	ft_putstr_fd("0x", 1);
	*res += 2;
	ptr = va_arg(aux, long long);
	if (t_flag->fl_poi && ptr == 0)
		return;
	tmp = ft_itoa_base(ptr, MIN);
	ft_space(t_flag->width - t_flag->size, t_flag->zero, res, t_flag);
	ft_putstr_fd(tmp, 1);
	*res += ft_strlen(tmp);
	free(tmp);
}

void	ft_conv_xadr(va_list aux, int *res, t_printf *t_flag)
{
	long long ptr;
	char *tmp;

	t_flag->conv = 0;
	ptr = va_arg(aux, unsigned int);
	if (t_flag->fl_poi && ptr == 0)
		return;
	ft_handle_spaceadd(res, t_flag, ptr);
	tmp = ft_itoa_base(ptr, MIN);
	//ft_space(t_flag->width - t_flag->size, t_flag->zero, res, t_flag);
	
	ft_putstr_fd(tmp, 1);
	*res += ft_strlen(tmp);
	free(tmp);
}

void	ft_conv_majxadr(va_list aux, int *res, t_printf *t_flag)
{
	long long ptr;
	char *tmp;

	t_flag->conv = 0;
	ptr = va_arg(aux, unsigned int);
	if (t_flag->fl_poi && ptr == 0)
		return;
	tmp = ft_itoa_base(ptr, CAP);
	ft_space(t_flag->width - t_flag->size, t_flag->zero, res, t_flag);
	ft_putstr_fd(tmp, 1);
	*res += ft_strlen(tmp);
	free(tmp);
}
