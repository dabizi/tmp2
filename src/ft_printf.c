/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:10:07 by jgrandne          #+#    #+#             */
/*   Updated: 2019/10/25 15:36:51 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "../inc/ft_printf.h"
#include "../libft/libft.h"

int				ft_printchar(va_list aux)
{
	int c;

	c = va_arg(aux, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int				ft_printstr(va_list aux)
{
	char *str;

	str = va_arg(aux, char *);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int			ft_printnbr(va_list aux)
{
	int nb;

	nb = va_arg(aux, int);
	ft_putnbr_fd(nb, 1);
	return (ft_strlen(ft_itoa(nb)));
}

int			ft_printnbru(va_list aux)
{
	unsigned int nb;

	nb = va_arg(aux, unsigned int);
	ft_putnbru_fd(nb, 1);
	return (ft_strlen(ft_itoau(nb)));
}

int			ft_printptr(va_list aux, int cse)
{
	long long ptr;
	char *tmp;
	int			len;

	if (cse == 1)
		ft_putstr_fd("0x", 1);
	ptr = va_arg(aux, long long);
	if (cse == 1 || cse == 2)
		tmp = ft_itoa_base(ptr, MIN);
	else
		tmp = ft_itoa_base(ptr, CAP);
	if (cse != 1)
		ft_putstr_fd(tmp + 4, 1);
	else
		ft_putstr_fd(tmp, 1);
	len = ft_strlen(tmp);
	free(tmp);
	return (len + ((cse == 1) ? 2 : -4));
}

static int			ft_switch(char *str, va_list aux)
{
	int nb;
	char c;

	c = str[0];
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
		ft_putchar_fd('%', 1);
//TODO
	else
		return (-1);
	return (nb);
}

t_printf			*ft_newsegment(int i)
{
	t_printf	*seg;

	if (!(seg = malloc(sizeof(t_printf))))
		return (0);
	seg->i = 0;
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
	if (size <= 0 || !(str = ft_switch(str, aux)))
		return (ft_abort(seg, NULL));
	return (size);
}

int					ft_printf(const char *str, ...)
{
	va_list		aux;
	int			size;
	int			i;
	t_list		t_flags;
	int			res;

	i = 0;
	va_start(aux, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			size = ft_getsegment((char *)str + i, aux, i);
			if (size > 0)
				i += size;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			i++;
			res++;
		}
	}
	va_end(aux);
	return (ft_output(1));
}
