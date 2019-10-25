/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:56:33 by jgrandne          #+#    #+#             */
/*   Updated: 2019/10/25 19:20:20 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_parse_conv(int *i, const char *str, va_list aux, int *res)
{
	*i += 1;
	str[*i] == 'c' ? ft_conv_char(aux, res) : 0;
	str[*i] == 's' ? ft_conv_str(aux, res) : 0;
	str[*i] == 'p' ? ft_conv_adr(aux, res, PTR) : 0;
	str[*i] == 'd' ? ft_conv_int(aux, res) : 0;
	str[*i] == 'i' ? ft_conv_int(aux, res) : 0;
	str[*i] == 'u' ? ft_conv_uint(aux, res) : 0;
	str[*i] == 'x' ? ft_conv_adr(aux, res, MXADR) : 0;
	str[*i] == 'X' ? ft_conv_adr(aux, res, XADR) : 0;
	str[*i] == '%' ? ft_conv_per(res) : 0;
	/*
	str[*i] == '-' ? ft_conv_int(aux, res) : 0;
	str[*i] == '0' ? ft_conv_int(aux, res) : 0;
	str[*i] == '.' ? ft_conv_int(aux, res) : 0;
	str[*i] == '*' ? ft_conv_int(aux, res) : 0;*/
}
