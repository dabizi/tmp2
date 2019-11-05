/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:18:01 by jgrandne          #+#    #+#             */
/*   Updated: 2019/11/05 20:50:41 by jgrandne         ###   ########.fr       */
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

void	ft_flags_m(int *res, t_printf *t_flag, char *str, int *i)
{
	int		nb;

	nb = ft_atoi(str);
	t_flag->fl_min = 1;
	if (nb > 1)
	{
		t_flag->space_after = nb;
	}
	else
		t_flag->exception = 1;
	if (nb == 0 && ft_isdigit(str[0]))
		*i += 1;
	else if (ft_isdigit(str[0]))
		*i += ft_strlen(ft_itoa(nb));
}

void	ft_flags_z(int *res, t_printf *t_flag, int *i)
{
	if (!t_flag->fl_min)
		t_flag->fl_zer = 1;
	*i += 1;
}

void	ft_flags_p(int *res, t_printf *t_flag, char *str, int *i)
{
	int		nb;

	*i += 1;
	nb = ft_atoi(str);
	t_flag->fl_poi = 1;
	if (nb > 1)
	{
		t_flag->width = nb;
	}
	else
		t_flag->exception = 1;
	if (t_flag->zero_before > t_flag->width)
	{

		t_flag->exception = 2;
	}
	if (!ft_isdigit(str[0]))
		t_flag->exception = 3;
	if (t_flag->zero_before > nb)
		t_flag->exception = 4;
	if (nb == 0 && ft_isdigit(str[0]))
		*i += 1;
	else if (ft_isdigit(str[0]))
		*i += ft_strlen(ft_itoa(nb));
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
	int		nb;

	nb = ft_atoi(str);
	if (nb > 1)
	{
		if (t_flag->fl_zer && !t_flag->zero_before)
		{
			t_flag->zero_before = nb;
//		printf("zero_before vaut %d\n", t_flag->zero_before);
		}
		else
		{
			t_flag->space_before = nb;
//			printf("space_before vaut %d\n", t_flag->space_before);
		}
}
	if (nb == 0 && ft_isdigit(str[0]))
		*i += 1;
	else if (ft_isdigit(str[0]))
		*i += ft_strlen(ft_itoa(nb));
}

	/*
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
		//	printf("here");
			if (t_flag->space_before > ft_atoi(str))
				{
				//TODO Bug here
				t_flag->zero_before = ft_atoi(str);
		//		printf("\n4\n");
				}
			else
			{
				t_flag->zero_before = ft_atoi(str);
				t_flag->space_before = 0;
			}
		}
		else if (t_flag->fl_poi && t_flag->fl_zer)
		{
			t_flag->zero_before = ft_atoi(str);
		}
		*/
//	}
//	*i += ft_strlen(ft_itoa(ft_atoi((str))));
//}
