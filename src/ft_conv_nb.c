/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:50:45 by jgrandne          #+#    #+#             */
/*   Updated: 2019/10/31 18:35:27 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_handle_space(int *res, t_printf *t_flag, int size)
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

//TODO space
//width -> 




//zero


}

void	ft_space(int nb, int cas, int *res, t_printf *t_flag)
{
	while (nb > 0)
	{
		if (cas)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		t_flag->width -= 1;
		*res += 1;
		nb--;
	}
}

void	ft_conv_int(va_list aux, int *res, t_printf *t_flag)
{
	int nb;

//	printf("Size vaut : %d\n", t_flag->size);
//	printf("Width vaut : %d\n", t_flag->width);
	t_flag->conv = 0;
	nb = va_arg(aux, int);
	ft_handle_space(res, t_flag, ft_strlen(ft_itoa(nb)));
/*	if (t_flag->width > 0 && t_flag->size > 0 && nb < 0)
		ft_space(t_flag->width - t_flag->size - 1, t_flag->zero, res, t_flag);
	else
		//ft_update(t_flag, ft_strlen(ft_itoa(nb)), res);
		ft_space(t_flag->width - t_flag->size - 1, t_flag->zero, res, t_flag);
		*/
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

//	printf("Size vaut : %d\n", t_flag->size);
//	printf("Width vaut : %d\n", t_flag->width);
}

void	ft_conv_uint(va_list aux, int *res, t_printf *t_flag)
{
	unsigned int nb;

	t_flag->conv = 0;
	nb = va_arg(aux, unsigned int);
	if (t_flag->fl_poi && nb == 0)
		return;
	//ft_space(t_flag, ft_strlen(ft_itoa(nb)), res, t_flag);
	ft_space(t_flag->width - t_flag->size, t_flag->zero, res, t_flag);
	ft_putnbru_fd(nb, 1);
	*res += ft_strlen(ft_itoau(nb));
}








































/*
void	ft_conv_adr(va_list aux, int *res, int cse, t_printf *t_flag)
{
	long long ptr;
	char *tmp;

//	printf("Zero vaut : %d\n", t_flag->zero);
//	printf("Width vaut : %d\n", t_flag->width);
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
	tmp = (cse == 2) ? ft_itoa_base(ptr, CAP) : ft_itoa_base(ptr, MIN);
	if (!t_flag->fl_min)
//	{
	//	t_flag->fl_poi ? 
		ft_space(t_flag->width - t_flag->size, t_flag->zero, res, t_flag);
	//	(ft_update(t_flag, ft_strlen(ft_itoa(ptr) + 1), res)) :
	//	(ft_update(t_flag, ft_strlen(ft_itoa(ptr)), res));
	//	ft_space(t_flag->width - t_flag->size, t_flag->zero, res, t_flag);
		ft_putstr_fd(tmp, 1);
//	}
	else
	{	
		ft_putstr_fd(tmp, 1);
		t_flag->fl_poi ? (ft_update(t_flag, ft_strlen(ft_itoa(ptr) + 1), res)) :
		(ft_update(t_flag, ft_strlen(ft_itoa(ptr)), res));
	}
	*res += ft_strlen(tmp);
	free(tmp);
}
*/
