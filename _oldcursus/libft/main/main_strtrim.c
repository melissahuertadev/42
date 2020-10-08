#include "libft.h"
#include <stdio.h>

int	main()
{	
    // gcc main_strtim.c ft_suprwsbeg.c ft_suprwsend.c ft_strlen.c

	/* *** strtim *** */
    char    *strtrimStr1 = "  012 3     ";
   // char    *strtrimRes1 = ft_suprwsbeg(strtrimStr1);
    //char    *strtrimRes2 = ft_suprwsend(strtrimRes1);
    printf("*****FT_STRTIM**\n");
    printf("Str1 before ft_suprwsbeg = '%s'\n", strtrimStr1);
    printf("Str1 after ft_suprwsbeg & ft_sprwsend = '%s'\n", ft_suprwsbeg(strtrimStr1));
    printf("Str1 after ft_suprwsbeg & ft_sprwsend = '%s'\n", ft_suprwsend(strtrimStr1));
    printf("**********************************************\n\n");

    return (0);
}