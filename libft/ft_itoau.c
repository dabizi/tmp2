/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoau.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:56:24 by jgrandne          #+#    #+#             */
/*   Updated: 2019/10/25 13:05:55 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			get_size(unsigned int n)
{
	unsigned int	size;

	size = 0;
	while (n >= 10)
	{
		n /= 10;
		++size;
	}
	return (size + 1);
}

char				*ft_itoau(unsigned int n)
{
	char			*res;
	int				size;
	int				index;
	unsigned long	nb;

	nb = (unsigned long)n;
	size = get_size(nb);
	index = 0;
	if (!(res = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	index = size - 1;
	while (nb >= 10)
	{
		res[index--] = (char)(nb % 10 + 48);
		nb /= 10;
	}
	res[index] = (char)(nb % 10 + 48);
	res[size] = '\0';
	return (res);
}
