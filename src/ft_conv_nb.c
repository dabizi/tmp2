/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:50:45 by jgrandne          #+#    #+#             */
/*   Updated: 2019/11/02 21:04:18 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"


void	ft_update_value(t_printf *t_flag, int neg)
{
/*
	printf("\n\nFlag zero vaut : %d\n", t_flag->fl_zer);
	printf("Zero before vaut : %d\n", t_flag->zero_before);
	printf("neg vaut : %d\n", neg);
	printf("Siz t fl vaut : %d\n", t_flag->size);
	printf("Width vaut : %d\n", t_flag->width);
	printf("Sta vaut : %d\n", t_flag->fl_sta);
	printf("Space before vaut : %d\n\n", t_flag->space_before);
	printf("Space after vaut : %d\n\n", t_flag->space_after);
*/
	if (t_flag->space_after)
		t_flag->space_after -= (t_flag->width);

//	printf("Space after vaut : %d\n\n", t_flag->space_after);
}

void	ft_handle_space(int *res, t_printf *t_flag, int size, int neg)
{
	if (t_flag->space_before)
		ft_space(t_flag->space_before - t_flag->size, 1, res, t_flag);
	if (t_flag->zero_before)
		ft_space(t_flag->zero_before - t_flag->size, 1, res, t_flag);

	if (neg)
	{
		write(1, "-", 1);
		if (t_flag->width > 0)
			write(1, "0", 1);
		//if (t_flag->width > 0)
	}
	if (t_flag->width > 0)
		ft_space(t_flag->width - t_flag->size, 0, res, t_flag);

}

//TODO Delete old handle space

/*	if (t_flag->fl_sta)
	{
	//	printf("1");
		ft_space(t_flag->space_before - size, t_flag->zero, res, t_flag);
	}
	//cas sans space ou 0
	if (t_flag->width < 0)
		return ;
	//cas avec space ou zero mais sans "."
	if (t_flag->width > 0 && t_flag->size == -1 && t_flag->fl_poi)
	{
		ft_space(t_flag->width - size, !t_flag->zero, res, t_flag);
		return ;
	}
	if (t_flag->width > 0 && t_flag->size == -1 && !t_flag->fl_poi)
	{
		ft_space(t_flag->width - size, 0, res, t_flag);
		return ;
	}
	if (t_flag->width > 0 && t_flag->size > -1)
	{
		ft_space(t_flag->width - t_flag->size -1, 0, res, t_flag) ;
		return ;
	}*/


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
	ft_putnbr_fd(nb, 1);
	*res += t_flag->size;
	if (t_flag->space_after > 0)
		ft_space(t_flag->space_after, 1, res, t_flag);
}


/*
	if (nb < 0 && t_flag->width != -1)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	
	if (t_flag->fl_poi && nb == 0)
		return;
	if (t_flag->fl_poi && t_flag->width > ft_strlen(ft_itoa(nb)))
	{
		if (t_flag->size > t_flag->width)
		{
//			printf("case 1");
			ft_space(t_flag->size - ft_strlen(ft_itoa(nb)), 1, res, t_flag);
		
		}
		else
		{
//			printf("case 2");
				ft_space(t_flag->width - ft_strlen(ft_itoa(nb)), 1, res, t_flag);

		}
	}
	if (t_flag->fl_poi && t_flag->width != - 1 && t_flag->size > t_flag->width - size_nb)
		ft_space(t_flag->width + 1 - t_flag->size, 1, res, t_flag);
		*/


void	ft_conv_uint(va_list aux, int *res, t_printf *t_flag)
{
	unsigned int nb;
	int			size_nb;

	t_flag->conv = 0;
	nb = va_arg(aux, unsigned int);
//	size_nb = ft_strlen(ft_itoa(nb));
//	ft_handle_space(res, t_flag, size_nb, ((nb < 0) ? 0 : 1));
	if (t_flag->fl_poi && nb == 0)
		return;
	
	ft_putnbru_fd(nb, 1);
	*res += size_nb;
	t_flag->width -= size_nb;
}
