/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:52:44 by jgrandne          #+#    #+#             */
/*   Updated: 2019/11/05 18:54:37 by jgrandne         ###   ########.fr       */
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

typedef struct	s_printf
{
	int		fl_min;
	int		fl_zer;
	int		fl_poi;
	int		fl_sta;
	int		space_before;
	int		space_after;
	int		zero_before;
	int		width;
	int		size;
	int		conv;
	int		percent;
	int		exception;
}				t_printf;

int				ft_printf(const char *str, ...);

void			ft_conv_char(va_list aux, int *res, t_printf *t_flag);
void			ft_conv_str(va_list aux, int *res, t_printf *t_flag);
t_printf		*ft_parse_conv(int *i, const char *str, va_list aux, int *res);
void			ft_conv_int(va_list aux, int *res, t_printf *t_flag);
void			ft_conv_uint(va_list aux, int *res, t_printf *t_flag);
void			ft_conv_adr(va_list aux, int *res, int cse, t_printf *t_flag);
void			ft_conv_per(int *res, t_printf *t_flag);
void			ft_flags_m(int *res, t_printf *t_flag, char *str, int *i);
void			ft_flags_n(char *str, t_printf *t_flag, int *i);
void			ft_flags_p(int *res, t_printf *t_flag, char *str, int *i);
void			ft_flags_s(va_list aux, int *res, t_printf *t_flag);
void			ft_flags_z(int *res, t_printf *t_flag, int *i);
int				ft_is_flag(char c, t_printf *t_flag, int *i);
void	ft_space(int nb, int cas, int *res, t_printf *t_flag);

void	ft_update_value(t_printf *t_flag, int neg);
void	ft_handle_space(int *res, t_printf *t_flag, int size, int neg);

void	ft_conv_padr(va_list aux, int *res, t_printf *t_flag);
void	ft_conv_xadr(va_list aux, int *res, t_printf *t_flag);
void	ft_conv_majxadr(va_list aux, int *res, t_printf *t_flag);

#endif
