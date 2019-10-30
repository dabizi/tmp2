/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:52:44 by jgrandne          #+#    #+#             */
/*   Updated: 2019/10/30 19:22:00 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

# define CAP "0123456789ABCDEF"
# define MIN "0123456789abcdef"
# define PTR 1
# define XADR 2
# define MXADR 3

typedef struct	s_printf
{
	int		minus;
	int		space;
	int		zero;
	int		width;
}				t_printf;

int				ft_printf(const char *str, ...);

void			ft_conv_char(va_list aux, int *res, t_printf *t_flag);
void			ft_conv_str(va_list aux, int *res, t_printf *t_flag);
t_printf		*ft_parse_conv(int *i, const char *str, va_list aux, int *res);
void			ft_conv_int(va_list aux, int *res, t_printf *t_flag);
void			ft_conv_uint(va_list aux, int *res);
void			ft_conv_adr(va_list aux, int *res, int cse);
void			ft_conv_per(int *res);
void			ft_flags_m(va_list aux, int *res, t_printf *t_flag);
void			ft_flags_n(char *str, t_printf *t_flag);
void			ft_flags_p(va_list aux, int *res, t_printf *t_flag);
void			ft_flags_s(va_list aux, int *res, t_printf *t_flag);
void			ft_flags_z(va_list aux, int *res, t_printf *t_flag);
int				ft_is_flag(char c);

#endif
