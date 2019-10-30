/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:56:33 by jgrandne          #+#    #+#             */
/*   Updated: 2019/10/30 17:22:54 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"


t_printf	*ft_init_struct(void)
{
	t_printf	*t_flag;

	if (!(t_flag = malloc(sizeof(t_printf))))
		return (NULL);
	t_flag->minus = 0;
	t_flag->space = 0;
	t_flag->zero = 0;
	t_flag->width = 0;
	return (t_flag);
}

int		ft_is_flag(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' ||
	c == 'x' || c == 'X' || c == '%' || c == '-' || c == '0' || c == '.' ||
	c == '*' || (c > '0' && c <= '9'))
		return (1);
	return (0);
}


t_printf	*ft_parse_conv(int *i, const char *str, va_list aux, int *res)
{
	t_printf	*t_flag;

	t_flag = ft_init_struct();
	while (ft_is_flag(str[*i]))
	{
		*i += 1;
		str[*i] > '0' && str[*i] <= '9' ? 
		ft_flags_n((char*)(str + *i), t_flag) : 0;
		str[*i] == 'c' ? ft_conv_char(aux, res) : 0;
		str[*i] == 's' ? ft_conv_str(aux, res) : 0;
		str[*i] == 'p' ? ft_conv_adr(aux, res, PTR) : 0;
		str[*i] == 'd' ? ft_conv_int(aux, res, t_flag) : 0;
		str[*i] == 'i' ? ft_conv_int(aux, res, t_flag) : 0;
		str[*i] == 'u' ? ft_conv_uint(aux, res) : 0;
		str[*i] == 'x' ? ft_conv_adr(aux, res, MXADR) : 0;
		str[*i] == 'X' ? ft_conv_adr(aux, res, XADR) : 0;
		str[*i] == '%' ? ft_conv_per(res) : 0;
		str[*i] == '0' ? ft_flags_z(aux, res, t_flag) : 0;
		str[*i] == '-' ? ft_flags_m(aux, res, t_flag) : 0;
		str[*i] == '.' ? ft_flags_p(aux, res, t_flag) : 0;
		str[*i] == '*' ? ft_flags_s(aux, res, t_flag) : 0;
	}
	free(t_flag);
	return (t_flag);
}
