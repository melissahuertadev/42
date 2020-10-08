#include "libft.h"
#include <string.h>
#include <stdio.h>

//gcc -Wall -Wextra -Werror main_memccpy.c ft_memccpy.c ft_strcpy.c 

int main()
{
    const char s[50] = "42 is life";
    char d[50];
    int i;

    i = 's';

    ft_strcpy(d, "text to be erased!");
    printf("Before memccpy = %s\n", d);
    memccpy(d, s, i,strlen(s));
    printf("After memcpy = %s\n", d);
    ft_memccpy(d, s, i,strlen(s));
    printf("After ft_memcpy = %s\n", d);
    return (0);
}