/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:46:43 by jgrandne          #+#    #+#             */
/*   Updated: 2019/10/31 17:50:02 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_out(char *str, int *res, t_printf *t_flag)
{
	int i;

	i = 0;
	while (t_flag->width != 0 && str[i])
	{
		ft_putchar_fd(str[i], 1);
		*res += 1;
		t_flag->width -= 1;
		i++;
	}
}

void	ft_conv_char(va_list aux, int *res, t_printf *t_flag)
{
	char c;

	t_flag->conv = 0;
	c = va_arg(aux, int);
	*res += 1;
	ft_putchar_fd(c, 1);
}

void	ft_conv_str(va_list aux, int *res, t_printf *t_flag)
{
	char *str;

	t_flag->conv = 0;
	str = va_arg(aux, char*);
	if (str)
		ft_out(str, res, t_flag);
	else
		ft_out("(null)", res, t_flag);
}
