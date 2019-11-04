/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_addr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:37:03 by jgrandne          #+#    #+#             */
/*   Updated: 2019/11/04 16:55:44 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_dis(t_printf *t_flag, int neg)
{

	printf("\n\nFlag zero vaut : %d\n", t_flag->fl_zer);
	printf("Zero before vaut : %d\n", t_flag->zero_before);
	printf("neg vaut : %d\n", neg);
	printf("Siz t fl vaut : %d\n", t_flag->size);
	printf("Width vaut : %d\n", t_flag->width);
	printf("Sta vaut : %d\n", t_flag->fl_sta);
	printf("Space before vaut : %d\n\n", t_flag->space_before);
	printf("Space after vaut : %d\n\n", t_flag->space_after);

}

void	ft_update_addr(t_printf *t_flag, int neg)
{

//	ft_display(t_flag, neg);
	if (t_flag->space_before)
	{
		t_flag->width = t_flag->space_before;
		t_flag->space_before -= (t_flag->zero_before + neg + t_flag->space_after);
//		printf("\n3");
		if (t_flag->fl_sta == 1)
		{
			t_flag->space_before -= t_flag->size - neg;
//			printf("\n1");
			}
		else if (t_flag->fl_sta > 1)
			;
		//	printf("\n2");
		else if (t_flag->fl_poi && !t_flag->fl_min && !t_flag->zero_before)
		{
//		printf("\n4");
			t_flag->space_before -= t_flag->size - neg;
		}
		else if (!t_flag->fl_poi)
		{
//		printf("\n5");
		t_flag->space_before -= t_flag->size - neg;
			if (t_flag->fl_zer)
			{
				t_flag->zero_before = t_flag->space_before;
				t_flag->space_before -= t_flag->zero_before;
			}
		}
		else if (t_flag->fl_poi && !t_flag->space_before)
		{
			t_flag->space_before = t_flag->zero_before - t_flag->size;
//			printf("\n6");
		}
	}
	if (!t_flag->space_before && t_flag->width > -1)
	{
		//if (t_flag->fl_zer)
			t_flag->zero_before = t_flag->width;
	}
	if (t_flag->zero_before)
	{
		if (t_flag->fl_poi && t_flag->fl_sta < 2 && t_flag->space_before)
		{
			t_flag->space_before = t_flag->zero_before;
			
		}
		t_flag->zero_before -= (t_flag->size);
	//	t_flag->space_before = t_flag->width - t_flag->space_before;
		if (t_flag->fl_poi && neg)
		{
			t_flag->zero_before += 1;
		//	t_flag->space_before = t_flag->zero_before;
		
		}
	//	printf("\n6");
	}
	if (t_flag->space_after)
	{
	t_flag->space_after -= (t_flag->size + t_flag->zero_before + t_flag->space_before);
	//		printf("\n7");
	}
	if (t_flag->fl_zer && t_flag->fl_sta && t_flag->space_before && 
	!t_flag->zero_before)
	{
		t_flag->zero_before = t_flag->space_before;
		t_flag->space_before = 0;
	//		printf("\n8");
	}
//	ft_display(t_flag, neg);
}

void	ft_conv_padr(va_list aux, int *res, t_printf *t_flag)
{
	long long ptr;
	char *tmp;

	t_flag->conv = 0;
	ptr = va_arg(aux, long long);
	if (!ptr && t_flag->fl_zer)
		ft_putstr_fd("0x", 1);
	if (t_flag->fl_poi && ptr == 0)
		return;
	tmp = ft_itoa_base(ptr, MIN);
	t_flag->size = ft_strlen(tmp);
	if (t_flag->space_before)
		t_flag->space_before -= 2;
	else if (t_flag->space_after)
		t_flag->space_after -= 2;
	ft_update_addr(t_flag, ((ptr < 0) ? 1 : 0));
	ft_handle_space(res, t_flag, 1, ((ptr < 0) ? 1 : 0));
	if (ptr || (!ptr && !t_flag->fl_zer))
		ft_putstr_fd("0x", 1);
	*res += 2;
	ft_putstr_fd(tmp, 1);
	*res += ft_strlen(tmp);
	free(tmp);
	if (t_flag->space_after > 0)
		ft_space(t_flag->space_after, 1, res, t_flag);
}

void	ft_conv_xadr(va_list aux, int *res, t_printf *t_flag)
{
	long long ptr;
	char *tmp;

	t_flag->conv = 0;
	ptr = va_arg(aux, unsigned int);
	if (t_flag->fl_poi && ptr == 0)
		return;
	tmp = ft_itoa_base(ptr, MIN);
	t_flag->size = ft_strlen(tmp);
	ft_update_addr(t_flag, ((ptr < 0) ? 1 : 0));
	ft_handle_space(res, t_flag, 1, ((ptr < 0) ? 1 : 0));
	ft_putstr_fd(tmp, 1);
	*res += ft_strlen(tmp);
	free(tmp);
	if (t_flag->space_after > 0)
		ft_space(t_flag->space_after, 1, res, t_flag);
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
	t_flag->size = ft_strlen(tmp);
	ft_update_addr(t_flag, ((ptr < 0) ? 1 : 0));
	ft_handle_space(res, t_flag, 1, ((ptr < 0) ? 1 : 0));
	ft_putstr_fd(tmp, 1);
	*res += ft_strlen(tmp);
	free(tmp);
	if (t_flag->space_after > 0)
		ft_space(t_flag->space_after, 1, res, t_flag);
}
