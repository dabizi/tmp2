/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:42:22 by jgrandne          #+#    #+#             */
/*   Updated: 2019/10/30 17:09:31 by jgrandne         ###   ########.fr       */
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
	printf("Test de d with flag\n");
	res = printf("%*d\n", 5, 3);
	printf("Return value : %d\n", res);
	res = ft_printf("%*d\n", 5, 3);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	printf("Test de d with flag\n");
	res = printf("%0*d\n", 5, 3);
	printf("Return value : %d\n", res);
	res = ft_printf("%0*d\n", 5, 3);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	printf("Test de C\n");
	res = ft_printf("Alabama %s\n", "alalalalalalalalalal");
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
	res = printf("Alabama is %0d\n", 123);
	printf("Return value : %d\n\n", res);
	res = ft_printf("Alabama is %0d\n", 123);
	printf("Return value : %d\n\n", res);
	ft_printf("\n");

*/
	res = printf("Alabama is %66d\n", -123);
	printf("Return value : %d\n", res);
	res = ft_printf("Alabama is %66d\n", -123);
	printf("Return value : %d\n", res);
	ft_printf("\n");


	res = printf("Alabama is %06d\n", 123);
	printf("Return value : %d\n", res);
	res = ft_printf("Alabama is %06d\n", 123);
	printf("Return value : %d\n", res);
	ft_printf("\n");


	res = printf("Alabama is %07d\n", -123);
	printf("Return value : %d\n", res);
	res = ft_printf("Alabama is %07d\n", -123);
	printf("Return value : %d\n", res);
	ft_printf("\n");


	return (0);
}
