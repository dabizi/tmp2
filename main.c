/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:42:22 by jgrandne          #+#    #+#             */
/*   Updated: 2019/10/23 17:55:09 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./inc/ft_printf.h"

int		main(int ac, char **av)
{
	int res;

	res = 0;
	ac = 1;
	printf("Test de Base\n");
	res = printf("Alabama\n");
	printf("Return value : %d\n", res);
	res = ft_printf("Alabama\n");
	printf("Return value : %d\n", res);
	printf("\n");

	printf("Test de C1\n");
	res = printf("%c\n", av[1][0]);
	printf("Return value : %d\n", res);
	res = ft_printf("%c\n", av[1][0]);
	printf("Return value : %d\n", res);
	printf("\n");

	printf("Test de C2\n");
	res = printf("Peint %c oo\n", av[1][0]);
	printf("Return value : %d\n", res);
	res = ft_printf("Peint %c oo\n", av[1][0]);
	printf("Return value : %d\n", res);
	printf("\n");

	printf("Test de S\n");
	res = printf("Alabama is %s holobomo\n", av[1]);
	printf("Return value : %d\n", res);
	res = ft_printf("Alabama is %s holobomo\n", av[1]);
	printf("Return value : %d\n", res);
	printf("\n");


	printf("Test de P\n");
	res = printf("Alabama is %p holobomo\n", av[1]);
	printf("Return value : %d\n", res);
	res = ft_printf("Alabama is %p holobomo\n", av[1]);
	printf("Return value : %d\n", res);
	printf("\n");

	printf("Test de I\n");
	res = printf("Alabama is %i holobomo\n", atoi(av[2]));
	printf("Return value : %d\n", res);
	res = ft_printf("Alabama is %i holobomo\n", atoi(av[2]));
	printf("Return value : %d\n", res);
	printf("\n");

	printf("Test de D\n");
	res = printf("Alabama is %d holobomo\n", atoi(av[2]));
	printf("Return value : %d\n", res);
	res = ft_printf("Alabama is %d holobomo\n", atoi(av[2]));
	printf("Return value : %d\n", res);
	printf("\n");
	return (0);
}
