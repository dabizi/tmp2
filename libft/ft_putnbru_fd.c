/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:41:13 by jgrandne          #+#    #+#             */
/*   Updated: 2019/10/25 12:42:13 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	ft_putnbru_fd(unsigned int n, int fd)
{
	if (n > 9)
		ft_putnbru_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}
