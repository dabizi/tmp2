/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:42:22 by jgrandne          #+#    #+#             */
/*   Updated: 2019/11/04 21:52:11 by jgrandne         ###   ########.fr       */
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

	res = printf("%c\n", 0);
	printf("Return value : %d\n\n", res);
	ft_printf("%c\n", 0);
	printf("Return value : %d\n\n", res);
	
	res = printf("%5.2x\n", 5427);
	printf("Return value : %d\n\n", res);
	ft_printf("%5.2x\n", 5427);
	printf("Return value : %d\n\n", res);
	
	res = printf("%5.2x\n", 0);
	printf("Return value : %d\n\n", res);
	ft_printf("%5.2x\n", 0);
	printf("Return value : %d\n\n", res);
	
	res = printf("%12c\n", 0);
	printf("Return value : %d\n\n", res);
	res = ft_printf("%12c\n", 0);
	printf("Return value : %d\n\n", res);

	res = printf("%d\n", -2147483647);
	printf("Return value : %d\n\n", res);
	res = ft_printf("%d\n", -2147483647);
	printf("Return value : %d\n\n", res);
	
	res = printf("%d\n", 2147483647);
	printf("Return value : %d\n\n", res);
	res = ft_printf("%d\n", 2147483647);
	printf("Return value : %d\n\n", res);
*/	
	res = printf("%03.2d\n", 0);
	printf("Return value : %d\n\n", res);
	res = ft_printf("%03.2d\n", 0);
	printf("Return value : %d\n\n", res);

res = printf("%03.1d\n", 0);
	printf("Return value : %d\n\n", res);
	res = ft_printf("%03.1d\n", 0);
	printf("Return value : %d\n\n", res);

	res = printf("%03.2d\n", 1);
	printf("Return value : %d\n\n", res);
	res = ft_printf("%03.2d\n", 1);
	printf("Return value : %d\n\n", res);
	
	res = printf("%03.2d\n", -1);
	printf("Return value : %d\n\n", res);
	res = ft_printf("%03.2d\n", -1);
	printf("Return value : %d\n\n", res);
	/*
	res = printf("%5.d\n", 0);
	printf("return value : %d\n\n", res);
	res = ft_printf("%5.d\n", 0);
	printf("return value : %d\n\n", res);

	res = printf("%5.d\n", 1);
	printf("return value : %d\n\n", res);
	res = ft_printf("%5.d\n", 1);
	printf("return value : %d\n\n", res);
	
	res = printf("%5.d\n", -1);
	printf("return value : %d\n\n", res);
	res = ft_printf("%5.d\n", -1);
	printf("return value : %d\n\n", res);

	res = printf("%d\n", 0);
	printf("Return value : %d\n\n", res);
	res = ft_printf("%d\n", 0);
	printf("Return value : %d\n\n", res);
	
	res = printf("%05.d\n", 0);
	printf("Return value : %d\n\n", res);
	res = ft_printf("%05.d\n", 0);
	printf("Return value : %d\n\n", res);
	
	res = printf("@moulitest: %5.d %5.0d\n", 0, 0);
	printf("Return value : %d\n\n", res);
	res = ft_printf("@moulitest: %5.d %5.0d\n", 0, 0);
	printf("Return value : %d\n\n", res);

	printf("%d\n\n", printf("%-.12u\n", -20000000));
	ft_printf("%d\n\n", ft_printf("%-.12u\n", -20000000));
	
	printf("\n");
	printf("%d\n\n", printf("%-.12d\n", -20000000));
	ft_printf("%d\n\n", ft_printf("%-.12d\n", -20000000));
	printf("\n");

	printf("%d\n\n", printf("%-.12i\n", -20000000));
	ft_printf("%d\n\n", ft_printf("%-.12i\n", -20000000));


	res = printf("%010.1d\n", 8473);
	printf("Return value : %d\n", res);
	res = ft_printf("%010.1d\n", 8473);
	printf("Return value : %d\n", res);
	ft_printf("\n");

res = printf("ret = %d\n", printf("%%p::[%010.1d]\n", -8473));
	printf("Return value : %d\n", res);
	res = ft_printf("ret = %d\n", ft_printf("%%p::[%010.1d]\n", -8473));
	printf("Return value : %d\n", res);
	ft_printf("\n");
	
	res = printf("ret = %d\n", printf("%%p::[%010.1d]\n", 8473));
	printf("Return value : %d\n", res);
	res = ft_printf("ret = %d\n", ft_printf("%%p::[%010.1d]\n", 8473));
	printf("Return value : %d\n", res);
	ft_printf("\n");
	
	res = printf("%010d\n", -8473);
	printf("Return value : %d\n", res);
	res = ft_printf("%010d\n", -8473);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("%*d\n", 12, -123);
	printf("%d\n", res);
	res = ft_printf("%*d\n", 12, -123);
	printf("%d\n\n", res);
	
	res = printf("%-20.010d\n", -123);
	printf("%d\n", res);
	res = ft_printf("%-20.010d\n", -123);
	printf("%d\n\n", res);

	res = printf("%-20.010d\n", 123);
	printf("%d\n", res);
	res = ft_printf("%-20.010d\n", 123);
	printf("%d\n\n", res);
	
	res = printf("%20.010d\n", -123);
	printf("%d\n", res);
	res = ft_printf("%20.010d\n", -123);
	printf("%d\n\n", res);
	
	res = printf("%-20.010d\n", 123);
	printf("%d\n", res);
	res = ft_printf("%-20.010d\n", 123);
	printf("%d\n\n", res);


	res = printf("%20.010d\n", 123);
	printf("%d\n", res);
	res = ft_printf("%20.010d\n", 123);
	printf("%d\n\n", res);

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


	res = printf("p31 %.4u\n", 100);
	printf("Return value : %d\n", res);
	res = ft_printf("p31 %.4u\n", 100);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("p32 %.10u\n", 100);
	printf("Return value : %d\n", res);
	res = ft_printf("p32 %.10u\n", 100);
	printf("Return value : %d\n", res);
	ft_printf("\n");


	res = printf("p33 %.50u\n", 100);
	printf("Return value : %d\n", res);
	res = ft_printf("p33 %.50u\n", 100);
	printf("Return value : %d\n", res);
	ft_printf("\n");
	
	res = printf("p36 %.0u\n", 0);
	printf("Return value : %d\n", res);
	res = ft_printf("p36 %.0u\n", 0);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("%");
	printf("Return value : %d\n", res);
	res = ft_printf("%");
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("%40.50d\n", 50);
	printf("Return value : %d\n", res);
	res = ft_printf("%40.50d\n", 50);
	printf("Return value : %d\n", res);
	ft_printf("\n");


	res = printf("%80.50d\n", 50);
	printf("Return value : %d\n", res);
	res = ft_printf("%80.50d\n", 50);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("%080.50d\n", -50);
	printf("Return value : %d\n", res);
	res = ft_printf("%080.50d\n", -50);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("%d\n", -589);
	printf("Return value : %d\n", res);
	res = ft_printf("%d\n", -589);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("%-8d\n", -2464);
	printf("Return value : %d\n", res);
	res = ft_printf("%-8d\n", -2464);
	printf("Return value : %d\n", res);
	ft_printf("\n");
    
	res = printf("%-8d\n", 2464);
	printf("Return value : %d\n", res);
	res = ft_printf("%-8d\n", 2464);
	printf("Return value : %d\n", res);
	ft_printf("\n");
	
	res = printf("%.5d\n", -2372);
	printf("Return value : %d\n", res);
	res = ft_printf("%.5d\n", -2372);
	printf("Return value : %d\n", res);
	ft_printf("\n");


	res = printf("%50.0d\n", 10);
	printf("Return value : %d\n", res);
	res = ft_printf("%50.0d\n", 10);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("%*.*d\n", 50, 5, 10);
	printf("Return value : %d\n", res);
	res = ft_printf("%*.*d\n", 50, 5, 10);
	printf("Return value : %d\n", res);
	ft_printf("\n");


	res = printf("%010d\n", -8473);
	printf("Return value : %d\n", res);
	res = ft_printf("%010d\n", -8473);
	printf("Return value : %d\n", res);
	ft_printf("\n");


	res = printf("%10d\n", -8473);
	printf("Return value : %d\n", res);
	res = ft_printf("%10d\n", -8473);
	printf("Return value : %d\n", res);
	ft_printf("\n");
	
	res = printf("ret = %d\n", printf("%%p::[%010d]\n", -8473));
	printf("Return value : %d\n", res);
	res = ft_printf("ret = %d\n", ft_printf("%%p::[%010d]\n", -8473));
	printf("Return value : %d\n", res);
	ft_printf("\n");
 
	res = printf("ret = %d\n", printf("%%p::[%10d]\n", -8473));
	printf("Return value : %d\n", res);
	res = ft_printf("ret = %d\n", ft_printf("%%p::[%10d]\n", -8473));
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("ret = %d\n", printf("%%p::[%.5d]\n", -8473));
	printf("Return value : %d\n", res);
	res = ft_printf("ret = %d\n", ft_printf("%%p::[%.5d]\n", -8473));
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("ret = %d\n", printf("%%p::[%01.1d]\n", -8473));
	printf("Return value : %d\n", res);
	res = ft_printf("ret = %d\n", ft_printf("%%p::[%01.1d]\n", -8473));
	printf("Return value : %d\n", res);
	ft_printf("\n");
   //Good
   //
   //

	res = printf("ret = %d\n", printf("%%p::[%01.50d]\n", -8473));
	printf("Return value : %d\n", res);
	res = ft_printf("ret = %d\n", ft_printf("%%p::[%01.50d]\n", -8473));
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("ret = %d\n", printf("%%p::[%1.50d]\n", -8473));
	printf("Return value : %d\n", res);
	res = ft_printf("ret = %d\n", ft_printf("%%p::[%1.50d]\n", -8473));
	printf("Return value : %d\n", res);
	ft_printf("\n");

//Goodd
	res = printf("ret = %d\n", printf("%%p::[%0100.50d]\n", -8473));
	printf("Return value : %d\n", res);
	res = ft_printf("ret = %d\n", ft_printf("%%p::[%0100.50d]\n", -8473));
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("ret = %d\n", printf("%%p::[%010d]\n", 8473));
	printf("Return value : %d\n", res);
	res = ft_printf("ret = %d\n", ft_printf("%%p::[%010d]\n", 8473));
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("ret = %d\n", printf("%%p::[%10d]\n", 8473));
	printf("Return value : %d\n", res);
	res = ft_printf("ret = %d\n", ft_printf("%%p::[%10d]\n", 8473));
	printf("Return value : %d\n", res);
	ft_printf("\n");
    
	res = printf("ret = %d\n", printf("%%p::[%.5d]\n", 8473));
	printf("Return value : %d\n", res);
	res = ft_printf("ret = %d\n", ft_printf("%%p::[%.5d]\n", 8473));
	printf("Return value : %d\n", res);
	ft_printf("\n");
	
	res = printf("ret = %d\n", printf("%%p::[%01.1d]\n", 8473));
	printf("Return value : %d\n", res);
	res = ft_printf("ret = %d\n", ft_printf("%%p::[%01.1d]\n", 8473));
	printf("Return value : %d\n", res);
	ft_printf("\n");
    


	res = printf("ret = %d\n", printf("%%p::[%01.50d]\n", 8473));
	printf("Return value : %d\n", res);
	res = ft_printf("ret = %d\n", ft_printf("%%p::[%01.50d]\n", 8473));
	printf("Return value : %d\n", res);
	ft_printf("\n");
    
	res = printf("ret = %d\n", printf("%%p::[%1.50d]\n", 8473));
	printf("Return value : %d\n", res);
	res = ft_printf("ret = %d\n", ft_printf("%%p::[%1.50d]\n", 8473));
	printf("Return value : %d\n", res);
	ft_printf("\n");
    
	res = printf("ret = %d\n", printf("%%p::[%0100.50d]\n", 8473));
	printf("Return value : %d\n", res);
	res = ft_printf("ret = %d\n", ft_printf("%%p::[%0100.50d]\n", 8473));
	printf("Return value : %d\n", res);
	ft_printf("\n");
    

	
	printf("Test de d with flag\n");
	res = printf("%0*d\n", 5, 3);
	printf("Return value : %d\n", res);
	res = ft_printf("%0*d\n", 5, 3);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("%-d\n", 123);
	printf("Return value : %d\n", res);
	res = ft_printf("%-d\n", 123);
	ft_printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("p12 %.0d\n", 0);
	printf("Return value : %d\n", res);
	res = ft_printf("p12 %.0d\n", 0);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("x12 %.d\n", 0);
	printf("Return value : %d\n", res);
	res = ft_printf("x12 %.d\n", 0);
	printf("Return value : %d\n", res);
	ft_printf("\n");
	
	res = printf("y12 %0d\n", 0);
	printf("Return value : %d\n", res);
	res = ft_printf("y12 %0d\n", 0);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("0t %d\n", 0);
	printf("Return value : %d\n", res);
	res = ft_printf("0t %d\n", 0);
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

	res = printf("p7 %.4d\n", 100);
	printf("Return value : %d\n", res);
	res = ft_printf("p7 %.4d\n", 100);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("p15 %.4i\n", 100);
	printf("Return value : %d\n", res);
	res = ft_printf("p15 %.4i\n", 100);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("%12d\n", -8425); //Donne "       -8425"
	printf("Return value : %d\n", res);
	res = ft_printf("%12d\n", -8425); //Donne "       -8425"
	printf("Return value : %d\n", res);
	ft_printf("\n");
	
	res = printf("%12.6d\n", -8425); //Donne "       -8425"
	printf("Return value : %d\n", res);
	res = ft_printf("%12.6d\n", -8425); //Donne "       -8425"
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

	res = printf("%10.x\n", -20);
	printf("Return value : %d\n", res);
	res = ft_printf("%10.2x\n", -20);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("%10.2x\n", -20);
	printf("Return value : %d\n", res);
	res = ft_printf("%10.2x\n", -20);
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

	res = printf("p20 %.0x\n", 0);
	printf("Return value : %d\n", res);
	res = ft_printf("p20 %.0x\n", 0);
	printf("Return value : %d\n", res);
	ft_printf("\n");
	
	res = printf("p28 %.0x\n", 0);
	printf("Return value : %d\n", res);
	res = ft_printf("p28 %.0x\n", 0);
	printf("Return value : %d\n", res);
	ft_printf("\n");


	res = printf("Hello 42 school! %s", NULL);
	printf("%010%");
	printf("%u", 4294967295);
	printf("%d\n", 2147483647);
	printf("Return value : %d\n", res);
	res = ft_printf("Hello 42 school! %s", NULL);
	ft_printf("%010%");
	ft_printf("%u", 4294967295);
	ft_printf("%d\n", 2147483647);
	printf("Return value : %d\n", res);
	ft_printf("\n");



	res = printf("%010x\n", 0);
	printf("Return value : %d\n", res);
	res = ft_printf("%010x\n", 0);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("%010d\n", 0);
	printf("Return value : %d\n", res);
	res = ft_printf("%010d\n", 0);
	printf("Return value : %d\n", res);
	ft_printf("\n");


	res = printf("%010x\n", 20);
	printf("Return value : %d\n", res);
	res = ft_printf("%010x\n", 20);
	printf("Return value : %d\n", res);
	ft_printf("\n");
	
	res = printf("%010x\n", -20);
	printf("Return value : %d\n", res);
	res = ft_printf("%010x\n", -20);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	printf("Last\n\n");

	res = printf("%10x\n", 20);
	printf("Return value : %d\n", res);
	res = ft_printf("%10x\n", 20);
	printf("Return value : %d\n", res);
	ft_printf("\n");



	res = printf("%10.x\n", -20);
	printf("Return value : %d\n", res);
	res = ft_printf("%10.2x\n", -20);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("%10.2x\n", -20);
	printf("Return value : %d\n", res);
	res = ft_printf("%10.2x\n", -20);
	printf("Return value : %d\n", res);
	ft_printf("\n");
	



//TODO STOPPED HERE



	res = printf("%-10x\n", 50);
	printf("Return value : %d\n", res);
	res = ft_printf("%-10x\n", 50);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("%-15x\n", 0);
	printf("Return value : %d\n", res);
	res = ft_printf("%-15x\n", 0);
	printf("Return value : %d\n", res);
	ft_printf("\n");


	res = printf("%*.*x\n", 50, 10, 2);
	printf("Return value : %d\n", res);
	res = ft_printf("%*.*x\n", 50, 10, 2);
	printf("Return value : %d\n", res);
	ft_printf("\n");



	res = printf("%c", 'a');
	printf("Return value : %d\n", res);
	res = ft_printf("%c", 'a');
	printf("Return value : %d\n", res);
	ft_printf("\n");
	
	res = printf("%10c", 't');
	printf("Return value : %d\n", res);
	res = ft_printf("%10c", 't');
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("%p\n", NULL);
	printf("Return value : %d\n", res);
	res = ft_printf("%p\n", NULL);
	printf("Return value : %d\n", res);
	ft_printf("\n");
	
	res = printf("%015p\n", NULL);
	printf("Return value : %d\n", res);
	res = ft_printf("%015p\n", NULL);
	printf("Return value : %d\n", res);
	ft_printf("\n");
	

	res = printf("%15p\n", NULL);
	printf("Return value : %d\n", res);
	res = ft_printf("%15p\n", NULL);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	res = printf("%-15p\n", NULL);
	printf("Return value : %d\n", res);
	res = ft_printf("%-15p\n", NULL);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	printf("%d\n\n", printf("4unsigned 1 %12u unsigned 2 %12u\n\n", 42, -42));
	ft_printf("%d\n\n", ft_printf("4unsigned 1 %12u unsigned 2 %12u\n\n", 42, -42));
	printf("\n");
	
	res = printf("%12u\n", -42);
	printf("Return value : %d\n", res);
	res = ft_printf("%12u\n", -42);
	printf("Return value : %d\n", res);
	ft_printf("\n");
	
	res = printf("%12d\n", -42);
	printf("Return value : %d\n", res);
	res = ft_printf("%12d\n", -42);
	printf("Return value : %d\n", res);
	ft_printf("\n");

	printf("%d\n\n", printf("4unsigned 1 %-12u unsigned 2 %-12u\n\n", 42, -42));
	ft_printf("%d\n\n", ft_printf("4unsigned 1 %-12u unsigned 2 %-12u\n\n", 42, -42));
	printf("\n");

	printf("%d\n\n", printf("5unsigned 1 %0u unsigned 2 %0u\n\n", 42, -42));
	ft_printf("%d\n\n", ft_printf("5unsigned 1 %0u unsigned 2 %0u\n\n", 42, -42));
	printf("\n");
	
	printf("%d\n\n", printf("6unsigned 1 %012u unsigned 2 %012u\n\n", 42, -42));
	ft_printf("%d\n\n", ft_printf("6unsigned 1 %012u unsigned 2 %012u\n\n", 42, -42));
	printf("\n");

*/
	return (0);
}
