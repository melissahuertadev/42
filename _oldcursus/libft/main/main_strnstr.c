#include "libft.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    const char    *strstrHay = "Hey friends";
    const char    *strstrNe1 = "fri";
    const char    *strstrNe2 = "ey";


    //gcc -Wall -Wextra -Werror main_strnstr.c ft_strnstr.c ft_strlen.c

    //strnstr
    printf("*****FT_STRNSTR**\n");
    printf("String: '%s' , needle 1: '%s'\n", strstrHay, strstrNe1);
    printf("strnstr with needle 1 and n = 1: %s\n", strnstr(strstrHay, strstrNe1, 1));
    printf("ft_strnstr with needle 1 and n = 1: %s\n", ft_strnstr(strstrHay, strstrNe1, 1));
    printf("strnstr with needle 1 and n = 2: %s\n", strnstr(strstrHay, strstrNe1, 2));
    printf("ft_strnstr with needle 1 and n = 2: %s\n", ft_strnstr(strstrHay, strstrNe1, 2));
    printf("strnstr with needle 1 and n = 3: %s\n", strnstr(strstrHay, strstrNe1, 3));
    printf("ft_strnstr with needle 1 and n = 3: %s\n", ft_strnstr(strstrHay, strstrNe1, 3));
    printf("strnstr with needle 1 and n = 4: %s\n", strnstr(strstrHay, strstrNe1, 4));
    printf("ft_strnstr with needle 1 and n = 4:  %s\n", ft_strnstr(strstrHay, strstrNe1, 4));
    printf("strnstr with needle 1 and n = 5: %s\n", strnstr(strstrHay, strstrNe1, 5));
    printf("ft_strnstr with needle 1 and n = 5: %s\n", ft_strnstr(strstrHay, strstrNe1, 5));
    printf("strnstr with needle 1 and n = 6: %s\n", strnstr(strstrHay, strstrNe1, 6));
    printf("ft_strnstr with needle 1 and n = 6: %s\n", ft_strnstr(strstrHay, strstrNe1, 6));
    printf("strnstr with needle 1 and n = 7: %s\n", strnstr(strstrHay, strstrNe1, 7));
    printf("ft_strnstr with needle 1 and n = 7: %s\n", ft_strnstr(strstrHay, strstrNe1, 7));
    printf("********************\n");
    printf("String: '%s' , needle 2: '%s'\n", strstrHay, strstrNe2);
    printf("strnstr with needle 2 and n = 1: %s\n", strnstr(strstrHay, strstrNe2, 1));
    printf("ft_strnstr with needle 2 and n = 1: %s\n", ft_strnstr(strstrHay, strstrNe2, 1));
    printf("strnstr with needle 2 and n = 2: %s\n", strnstr(strstrHay, strstrNe2, 2));
    printf("ft_strnstr with needle 2 and n = 2: %s\n", ft_strnstr(strstrHay, strstrNe2, 2));
    printf("strnstr with needle 2 and n = 3: %s\n", strnstr(strstrHay, strstrNe2, 3));
    printf("ft_strnstr with needle 2 and n = 3: %s\n", ft_strnstr(strstrHay, strstrNe2, 3));
    printf("strnstr with needle 2 and n = 4: %s\n", strnstr(strstrHay, strstrNe2, 4));
    printf("ft_strnstr with needle 2 and n = 4: %s\n", ft_strnstr(strstrHay, strstrNe2, 4));
    printf("**********************************************\n");
    return (0);
}
