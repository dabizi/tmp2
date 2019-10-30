/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:42:22 by jgrandne          #+#    #+#             */
/*   Updated: 2019/10/30 22:00:14 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./inc/ft_printf.h"

int		main(int ac, char **av)
{
	int res;

	res = 0;
	ac = 1;


	/*
	printf("Test\n");
	res = printf("p0 % .3s\n", "cccc");
	printf("Return value : %d\n\n", res);
	res = ft_printf("p0 % .3s\n", "cccc");
	printf("Return value : %d\n\n", res);
	ft_printf("\n");


	res = printf("p15 %.4i\n", 100);
	printf("Return value : %d\n", res);
	res = ft_printf("p15 %.4i\n", 100);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	printf("Test de d1 with flag\n");
	res = printf("%*d\n", 5, 3);
	printf("Return value : %d\n", res);
	res = ft_printf("%*d\n", 5, 3);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	printf("Test de d2 with flag\n");
	res = printf("%0*d\n", 5, 3);
	printf("Return value : %d\n", res);
	res = ft_printf("%0*d\n", 5, 3);
	printf("Return value : %d\n", res);
	ft_printf("\n");

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

	printf("Test de u\n");
	res = printf("Alabama is %u holobomo\n", atoi(av[2]));
	printf("Return value : %d\n", res);
	res = ft_printf("Alabama is %u holobomo\n", atoi(av[2]));
	printf("Return value : %d\n", res);
	printf("\n");

	printf("Test de D\n");
	res = printf("Alabama is %d holobomo\n", atoi(av[2]));
	printf("Return value : %d\n", res);
	res = ft_printf("Alabama is %d holobomo\n", atoi(av[2]));
	printf("Return value : %d\n", res);
	printf("\n");

	printf("Test de x\n");
	res = printf("Alabama is %x holobomo\n", (unsigned int)atoi(av[1]));
	printf("Return value : %d\n", res);
	res = ft_printf("Alabama is %x holobomo\n", (unsigned int)atoi(av[1]));
	printf("Return value : %d\n", res);
	printf("\n");

	printf("Test de X\n");
	res = printf("Alabama is %X holobomo\n", (unsigned int)atoi(av[1]));
	printf("Return value : %d\n", res);
	res = ft_printf("Alabama is %X holobomo\n", (unsigned int)atoi(av[1]));
	printf("Return value : %d\n", res);
	printf("\n");

	printf("Test de C\n");
	res = printf("%0-c\n", 'a');
	printf("Return value : %d\n", res);
	res = ft_printf("%0-c\n", 'a');
	printf("Return value : %d\n", res);
	ft_printf("\n");
	
	printf("Test de d with flag\n");
	res = printf("%0*d\n", 5, 3);
	printf("Return value : %d\n", res);
	res = ft_printf("%0*d\n", 5, 3);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	printf("Test de C\n");
	res = printf("%-d\n", 123);
	printf("Return value : %d\n", res);
	res = ft_printf("%-d\n", 123);
	ft_printf("Return value : %d\n", res);
	ft_printf("\n");


	printf("Test de S\n");
	res = printf("%c\n", 'a');
	printf("Return value : %d\n", res);
	res = ft_printf("%c\n", 'a');
	ft_printf("Return value : %d\n", res);
	ft_printf("\n");


	printf("Test\n");
	res = printf("p0 % .3s\n", "cccc");
	printf("Return value : %d\n\n", res);
	res = ft_printf("p0 % .3s\n", "cccc");
	printf("Return value : %d\n\n", res);
	ft_printf("\n");


	res = printf("p3 %.4s\n", NULL);
	printf("Return value : %d\n", res);
	res = ft_printf("p3 %.4s\n", NULL);
	printf("Return value : %d\n", res);
	ft_printf("\n");


	res = printf("p7 %.4d\n", 100);
	printf("Return value : %d\n", res);
	res = ft_printf("p7 %.4d\n", 100);
	printf("Return value : %d\n", res);
	ft_printf("\n");

*/
	res = printf("p12 %.0d\n", 0);
	printf("Return value : %d\n", res);
	res = ft_printf("p12 %.0d\n", 0);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("p15 %.4i\n", 100);
	printf("Return value : %d\n", res);
	res = ft_printf("p15 %.4i\n", 100);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("p6 %.0d\n", 100);
	printf("Return value : %d\n", res);
	res = ft_printf("p6 %.0d\n", 100);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("p10 %.1d\n", 100);
	printf("Return value : %d\n", res);
	res = ft_printf("p10 %.1d\n", 100);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("p14 %.0i\n", 100);
	printf("Return value : %d\n", res);
	res = ft_printf("p14 %.0i\n", 100);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("p18 %.1i\n", 100);
	printf("Return value : %d\n", res);
	res = ft_printf("p18 %.1i\n", 100);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("0t %d\n", 0);
	printf("Return value : %d\n", res);
	res = ft_printf("0t %d\n", 0);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("p19 %.3x\n", 100);
	printf("Return value : %d\n", res);
	res = ft_printf("p19 %.3x\n", 100);
	printf("Return value : %d\n", res);
	ft_printf("\n");


	res = printf("p21 %.3x\n", 100);
	printf("Return value : %d\n", res);
	res = ft_printf("p21 %.3x\n", 100);
	printf("Return value : %d\n", res);
	ft_printf("\n");


	res = printf("p23 %.4x\n", 100);
	printf("Return value : %d\n", res);
	res = ft_printf("p23 %.4x\n", 100);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("p24 %.10x\n", 100);
	printf("Return value : %d\n", res);
	res = ft_printf("p24 %.10x\n", 100);
	printf("Return value : %d\n", res);
	ft_printf("\n");
	
	return (0);
}
