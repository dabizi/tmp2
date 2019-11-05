/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:50:45 by jgrandne          #+#    #+#             */
/*   Updated: 2019/11/05 21:02:30 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_display(t_printf *t_flag, int neg)
{
	printf("\n\nFlag zero vaut : %d\n", t_flag->fl_zer);
	printf("Flag star vaut : %d\n", t_flag->fl_sta);
	printf("Flag minus vaut : %d\n", t_flag->fl_min);
	printf("Flag exception vaut : %d\n", t_flag->exception);
	printf("Flag point vaut : %d\n", t_flag->fl_poi);
	printf("Zero before vaut : %d\n", t_flag->zero_before);
	printf("neg vaut : %d\n", neg);
	printf("Siz t fl vaut : %d\n", t_flag->size);
	printf("Width vaut : %d\n", t_flag->width);
	printf("Sta vaut : %d\n", t_flag->fl_sta);
	printf("Space before vaut : %d\n", t_flag->space_before);
	printf("Space after vaut : %d\n\n", t_flag->space_after);
}


void	ft_update_value(t_printf *t_flag, int neg)
{
//	ft_display(t_flag, neg);
//	if (t_flag->zero_before > t_flag->width && t_flag->width != 1)
//		t_flag->space_before = t_flag->zero_before - t_flag->width + neg;

	if (t_flag->exception == 1)
	{
		printf("exception 1");
	//	t_flag->space_before += t_flag->zero_before;
	//	t_flag->zero_before = 0;
	}
	else if (t_flag->exception == 2)
	{
		//if (t_flag->zero_before < t_flag->size)
		//	t_flag->zero_before = 0;
	//	else
	//		t_flag->zero_before -= t_flag->width;
	//	if (t_flag->space_before < t_flag->size)
	//		t_flag->space_before = 0;
	//	else
	//		t_flag->space_before -= 2;
		printf("exception 2");
//	ft_display(t_flag, neg);

	}
	else if (t_flag->exception == 3)
	{
	//	ft_display(t_flag, neg);
	//	t_flag->space_before -= 1;
	//	t_flag->zero_before = 0;
		printf("exception 3");
	}
	else if (t_flag->exception == 4)
	{
		t_flag->space_before = t_flag->zero_before;
//		printf("ola");
//		if (t_flag->width > -1)
//		{
//			t_flag->space_before -= t_flag->width - t_flag->size;
//			t_flag->zero_before -= t_flag->width - t_flag->size;
//		}
	}
	if (t_flag->space_before && t_flag->width > -1)
		t_flag->space_before -= t_flag->width + neg;

	if (t_flag->zero_before && t_flag->width > -1)
		t_flag->zero_before -= t_flag->width + t_flag->size;
//	if (t_flag->space_before)
//		t_flag->space_before -= t_flag->size;
	if (t_flag->width > -1 && !t_flag->zero_before)
		t_flag->zero_before += t_flag->width - t_flag->size + neg;
	if (t_flag->width > t_flag->zero_before)
		t_flag->zero_before = t_flag->width - t_flag->size + neg;
//	if (t_flag->width > t_flag->space_before)
//		t_flag->space_before = 0;
//	ft_display(t_flag, neg);



}

void	ft_handle_space(int *res, t_printf *t_flag, int size, int neg)
{
	if (t_flag->space_before)
		ft_space(t_flag->space_before, 1, res, t_flag);
	if (neg)
	{
		write(1, "-", 1);
	}
	if (t_flag->zero_before)
		ft_space(t_flag->zero_before, 0, res, t_flag);
}

void	ft_space(int nb, int cas, int *res, t_printf *t_flag)
{
	while (nb > 0)
	{
		if (cas)
			ft_putchar_fd(' ', 1);
		else
			ft_putchar_fd('0', 1);
		//t_flag->width -= 1;
		*res += 1;
		nb--;
	}
}

void	ft_conv_int(va_list aux, int *res, t_printf *t_flag)
{
	long	nb;

	t_flag->conv = 0;
	nb = va_arg(aux, int);
	t_flag->size = ft_strlen(ft_itoa(nb));
	ft_update_value(t_flag, ((nb < 0) ? 1 : 0));
	ft_handle_space(res, t_flag, 1, ((nb < 0) ? 1 : 0));
	if (nb < 0)
		nb = -nb;
	if (t_flag->exception == 1 && nb == 0)
		return ;
	if (t_flag->exception == 3)
		return ;
	ft_putnbr_fd(nb, 1);
	*res += t_flag->size;
	if (t_flag->space_after > 0)
		ft_space(t_flag->space_after, 1, res, t_flag);
}

void	ft_conv_uint(va_list aux, int *res, t_printf *t_flag)
{
	long long nb;
	int			size_nb;

	t_flag->conv = 0;
	nb = (long long)va_arg(aux, unsigned int);
	t_flag->size = ft_strlen(ft_lgitoa(nb));
	ft_update_value(t_flag, ((nb < 0) ? 1 : 0));
	ft_handle_space(res, t_flag, 1, ((nb < 0) ? 1 : 0));
	ft_putnbru_fd(nb, 1);
	*res += t_flag->size;
	if (t_flag->space_after > 0)
		ft_space(t_flag->space_after, 1, res, t_flag);
}
