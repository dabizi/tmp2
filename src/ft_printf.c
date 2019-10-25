/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:10:07 by jgrandne          #+#    #+#             */
/*   Updated: 2019/10/25 17:01:47 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*static int			ft_switch(char c, va_list aux)
{
	int nb;

	nb = 0;
	if (c =='c')
		nb += ft_printchar(aux);
	else if (c == 's')
		nb += ft_printstr(aux);
	else if (c == 'p')
		nb += ft_printptr(aux, 1);
	else if (c == 'd')
		nb += ft_printnbr(aux);
	else if (c == 'i')
		nb += ft_printnbr(aux);
	else if (c == 'u')
		nb += ft_printnbru(aux);
	else if (c == 'x')
		nb += ft_printptr(aux, 2);
	else if (c == 'X')
		nb += ft_printptr(aux, 3);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		nb += 1;
	}
	else
		return (-1);
	return (nb);
}*/

t_printf			*ft_newsegment(int i)
{
	t_printf	*seg;

	if (!(seg = malloc(sizeof(t_printf))))
		return (0);
	seg->i = i;
	seg->len = 0;
	seg->space = 0;
	seg->zero = 0;
	return (seg);
}

int					ft_abort(t_printf *seg, char *str)
{
	if (seg)
		free(seg);
	if (str)
		free(str);
	return (-1);
}

int					ft_getsegment(char *str, va_list aux, int i)
{
	t_printf	*seg;
	char		c;
	int			size;

	size = 0;
	if (!(seg = ft_newsegment(i)))
		return (-1);
	

	return (size);
}

int					ft_printf(const char *str, ...)
{
	va_list		aux;
	int			size;
	int			i;
	t_printf	*seg;

	i = 0;
	va_start(aux, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			seg = ft_newsegment(i);
			ft_check_conv(seg, (char *)str + i, aux);
			i += 2;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			i++;
		}
	}
	va_end(aux);
	return (i);
	//return (ft_output(1));
}
