/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:18:01 by jgrandne          #+#    #+#             */
/*   Updated: 2019/10/30 15:02:47 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_conv_per(int *res)
{
	ft_putchar_fd('%', 1);
	*res += 1;
}

void	ft_flags_m(va_list aux, int *res)
{
	ft_putchar_fd('-', 1);
	*res += 1;
}

void	ft_flags_z(va_list aux, int *res)
{
	ft_putchar_fd('0', 1);
	*res += 1;

}

void	ft_flags_p(va_list aux, int *res)
{
	ft_putchar_fd('+', 1);
	*res += 1;
}


void	ft_flags_s(va_list aux, int *res)
{
	ft_putchar_fd('*', 1);
	*res += 1;
}
