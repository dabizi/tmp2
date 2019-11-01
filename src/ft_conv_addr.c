/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_addr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:37:03 by jgrandne          #+#    #+#             */
/*   Updated: 2019/11/01 17:06:47 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"


void	ft_handle_spaceadd(int *res, t_printf *t_flag, int size, int neg)
{

//	printf("\n\nPoint vaut : %d\n", t_flag->fl_poi);
//	printf("Siz vaut : %d\n", t_flag->size);
//	printf("Width vaut : %d\n", t_flag->width);
//	printf("Sta vaut : %d\n", t_flag->fl_sta);
//	printf("Space vaut : %d\n", t_flag->space_before);

	if (t_flag->fl_sta)
	{
		if (t_flag->space_after)
		{
		
			printf("1");
		/*	printf("\n\nPoint vaut : %d\n", t_flag->fl_poi);
			printf("Siz vaut : %d\n", t_flag->size);
			printf("Width vaut : %d\n", t_flag->width);
			printf("Sta vaut : %d\n", t_flag->fl_sta);
			printf("Space vaut : %d\n", t_flag->space_before);
		*/
		ft_space(t_flag->space_before - t_flag->space_after, 0, res, t_flag);
		}
		ft_space(t_flag->space_after - 1, !t_flag->zero, res, t_flag);
	}

	//cas sans space ou 0
	if (t_flag->width < 0)
		return ;
	//cas avec space ou zero mais sans "."
	if (t_flag->width > 0 && t_flag->size == -1 && t_flag->fl_poi)
	{
		printf("2");
	//	printf("size : %d\n", size);
		ft_space(t_flag->width - size, !t_flag->zero, res, t_flag);
		return ;
	}
	if (t_flag->width > 0 && t_flag->size == -1 && !t_flag->fl_poi)
	{
		printf("3");
	//	printf("size : %d\n", size);
		ft_space(t_flag->width - size, t_flag->zero, res, t_flag);
		return ;
	}
	if (t_flag->width > 0 && t_flag->size > -1)
	{
	
		printf("4");
	/*	printf("\n\nPoint vaut : %d\n", t_flag->fl_poi);
		printf("Siz vaut : %d\n", t_flag->size);
		printf("Width vaut : %d\n", t_flag->width);
		printf("Sta vaut : %d\n", t_flag->fl_sta);
		printf("Space vaut : %d\n", t_flag->space_before);
	*/	ft_space(t_flag->size, 0, res, t_flag);
		return ;
	}

/*
	printf("\n\nSiz vaut : %d\n", t_flag->size);
	printf("Width vaut : %d\n", t_flag->width);
	printf("Sta vaut : %d\n", t_flag->fl_sta);
	printf("Space vaut : %d\n\n", t_flag->space_before);


*/
/*
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
	*/
}



void	ft_conv_padr(va_list aux, int *res, t_printf *t_flag)
{
	long long ptr;
	char *tmp;

	t_flag->conv = 0;
	//ft_putstr_fd("0x", 1);
	t_flag->width -= 2;
//	*res += 2;
	ptr = va_arg(aux, long long);
	if (!ptr && t_flag->zero)
		ft_putstr_fd("0x", 1);
	if (t_flag->fl_poi && ptr == 0)
		return;
	tmp = ft_itoa_base(ptr, MIN);
	if (!t_flag->fl_min)
		ft_handle_spaceadd(res, t_flag, ft_strlen(tmp), 0);
	if (ptr || (!ptr && !t_flag->zero))
		ft_putstr_fd("0x", 1);
//	t_flag->width -= 2;
	*res += 2;
	ft_putstr_fd(tmp, 1);
	if (t_flag->fl_min)
		ft_handle_spaceadd(res, t_flag, ft_strlen(tmp), 0);
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
	tmp = ft_itoa_base(ptr, MIN);
	if (!t_flag->fl_min)
		ft_handle_spaceadd(res, t_flag, ft_strlen(tmp), 0);
	ft_putstr_fd(tmp, 1);
	if (t_flag->fl_min)
		ft_handle_spaceadd(res, t_flag, ft_strlen(tmp), 0);
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
	if (!t_flag->fl_min)
		ft_handle_spaceadd(res, t_flag, ft_strlen(tmp), 0);
	ft_putstr_fd(tmp, 1);
	if (t_flag->fl_min)
		ft_handle_spaceadd(res, t_flag, ft_strlen(tmp), 0);
	*res += ft_strlen(tmp);
	free(tmp);
}
