#include "libft.h"
#include <stdio.h>

int	main()
{	
   	/* *** itoa *** */
    
    int itoaInt1 = 914;
    int itoaInt2 = -589;
    
    printf("*****FT_ITOA**\n");
    printf("dig %i\n", itoaInt1);
    printf("converted to string: %s\n", ft_itoa(itoaInt1));
    printf("---\n");
    printf("dig %i\n", itoaInt2);
    printf("converted to string: %s\n", ft_itoa(itoaInt2));

/*

    int     n1 = 1;
    int     n2 = 5;
    char    c1 = 'A';
    char    c2 = 'Z';

    //gcc main_itoa.c ft_genswap.c ft_memcpy.c
    printf("Testing ft_genswap\n");    
    printf("Before ft_genswap: n1 = %i, n2 = %i\n", n1, n2);
    ft_genswap(&n1, &n2, sizeof(n1));
    printf("After ft_genswap: n1 = %i, n2 = %i\n", n1, n2);
    printf("Before ft_genswap: c1 = %c, c2 = %c\n", c1, c2);
    ft_genswap(&c1, &c2, sizeof(c1));
    printf("After ft_genswap: c1 = %c, c2 = %c\n", c1, c2);
*/

    return (0);
}