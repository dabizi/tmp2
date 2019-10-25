/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:52:44 by jgrandne          #+#    #+#             */
/*   Updated: 2019/10/25 16:58:43 by jgrandne         ###   ########.fr       */
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
	int		i;
	int		len;
	int		space;
	int		zero;
}				t_printf;

int				ft_printf(const char *str, ...);
int				ft_check_conv(t_printf *seg, char *str, va_list aux);
int				ft_check_flags(char *str, va_list aux);

#endif
