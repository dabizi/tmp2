/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:55:27 by jgrandne          #+#    #+#             */
/*   Updated: 2019/10/23 18:10:21 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_itoa_base(long long nb, char *base)
{
	long long			count;
	unsigned long long	tmp;
	char				*res;
	unsigned long		b_len;

	b_len = ft_strlen(base);
	count = (nb < 0) ? 2 : 1;
	tmp = (nb < 0) ? -nb : nb;
	while (tmp >= b_len && (tmp /= b_len))
		++count;
	tmp = (nb < 0) ? -nb : nb;
	if (!(res = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	if (nb < 0)
		res[0] = '-';
	res[count] = '\0';
	while (tmp >= b_len)
	{
		--count;
		res[count] = base[tmp % b_len];
		tmp /= b_len;
	}
	res[--count] = base[tmp % b_len];
	return (res);
}
