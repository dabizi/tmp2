/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:18:01 by jgrandne          #+#    #+#             */
/*   Updated: 2019/11/04 17:42:49 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_conv_per(int *res, t_printf *t_flag)
{
	t_flag->conv = 0;
	ft_space(t_flag->percent - 1, 1, res, t_flag);
	ft_putchar_fd('%', 1);
	*res += 1;
}

void	ft_flags_m(va_list aux, int *res, t_printf *t_flag)
{
	t_flag->fl_min = 1;
//	if (t_flag->fl_zer)
//		t_flag->fl_zer = 0;
}

void	ft_flags_z(va_list aux, int *res, t_printf *t_flag, int *i)
{
	if (!t_flag->fl_min)
		t_flag->fl_zer = 1;
	*i += 1;
}

void	ft_flags_p(va_list aux, int *res, t_printf *t_flag)
{
	t_flag->fl_poi = 1;
	if (t_flag->fl_min && !t_flag->space_before && !t_flag->space_after
	&& !t_flag->zero_before)
		t_flag->fl_min = 0;
//	if (t_flag->fl_zer)
//		t_flag->fl_zer = 0;
}

void	ft_flags_s(va_list aux, int *res, t_printf *t_flag)
{

	if (!t_flag->fl_sta)
	{
		t_flag->space_before = va_arg(aux, int);
	} else
	{
		t_flag->zero_before = va_arg(aux, int);
	}
	t_flag->fl_sta += 1;
}

void	ft_flags_n(char *str, t_printf *t_flag, int *i)
{
	if (ft_atoi(str) > 1)
	{
		if (t_flag->fl_zer)
		{
			if (!t_flag->zero_before)
			{
				t_flag->zero_before = ft_atoi(str);
		//		printf("\n1\n");
				}
		//	t_flag->fl_zer = 0;
		}
		if (!t_flag->space_after && t_flag->fl_min)
		{
			t_flag->space_after = ft_atoi(str);
		//	t_flag->fl_min = 0;
			}
		else if (!t_flag->space_before && !t_flag->fl_min)
		{
			if (t_flag->fl_poi)
			{
		//		printf("\n2\n");
				t_flag->zero_before = ft_atoi(str);
			}
			else
			{
			t_flag->space_before = ft_atoi(str);
				if (t_flag->zero_before)
				{
					t_flag->zero_before -= t_flag->space_before;
		//		printf("\n3\n");
				
				}

			}
		}
		else if (!t_flag->space_before && t_flag->fl_poi)
		{
		t_flag->width = ft_atoi(str);
		//		printf("\n7\n");
				}
		else if (t_flag->space_before && t_flag->fl_poi)
		{
			if (t_flag->space_before > ft_atoi(str))
				{
				t_flag->zero_before = ft_atoi(str);
		//		printf("\n4\n");
				}
			else
			{
				t_flag->zero_before = ft_atoi(str);
				t_flag->space_before = 0;
		//		printf("\n5\n");
			}
		}
		else if (t_flag->fl_poi && t_flag->fl_zer)
		{
			t_flag->zero_before = ft_atoi(str);
		//		printf("\n6\n");
		//	printf("hola");

			}
	}
	*i += ft_strlen(ft_itoa(ft_atoi((str))));
}
