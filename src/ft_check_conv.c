/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:27:52 by jgrandne          #+#    #+#             */
/*   Updated: 2019/10/25 17:19:34 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_check_conv(t_printf *seg, char *str, va_list aux)
{
	if (!ft_check_flags(str, aux))
		return (0);
	if (*str == 'c')
		ft_putchar_fd('c', 1);


// cspdiuxX%
// -0.*

	return (0);
}

int		ft_check_flags(char *str, va_list aux)
{
	while (*str == '0' || *str == '-' || *str == '*' || *str == '.')
	{
		if (*str == '0')
		{
			printf("0\n");
			return (1);
		}
		else if (*str == '-')
		{
			printf("-\n");
			return (1);
		}
		else if (*str == '*')
		{
			printf("*\n");
			return (1);
		}
		else if (*str == '.')
		{
			printf(".i\n");
			return (1);
		}
		++*str;
	}
	return (0);
}
