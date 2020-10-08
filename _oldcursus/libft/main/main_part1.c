#include "libft.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    char    bzeroStr[50] = "42 make people crazy";
    char    memsetStr[50] = "42 make people crazy";
    int     memsetInt = 'a';
    char    memchrStr[50] = "Four 678";
    int     memchrInt = 'r';
    char    memcmpStr1[20] = "C memcmp compares";
    char    memcmpStr2[20] = "C memcmp fails 42";
    char    strchrStr[30] = "Find this i here";
    int     strchrInt = 'i';
    const char    *strstrHay = "Hey friends";
    const char    *strstrNe1 = "fri";
    const char    *strstrNe2 = "ey";
    char    strcatDst[50] = "Hi newbie,";
    const char  strcatSrc[50] = " don't panic!";
    char    strncatDst[50] = "Do or do not.";
    const char  strncatSrc[50] = " There is no try.";
    char    strlcatDst[50] = "Do or do not.";
    const char  strlcatSrc[50] = " There is no try.";

    //gcc -Wall -Wextra -Werror main_part1.c ft_bzero.c ft_memset.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcat.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strlen.c 

    //bzero
    printf("*****FT_BZERO**\n");
    printf("Before ft_bzero = %s\n", bzeroStr);
    bzero(bzeroStr, 50);
    printf("After bzero = %s\n", bzeroStr);
    ft_bzero(bzeroStr, 50);
    printf("After ft_bzero = %s\n", bzeroStr);
    printf("**********************************************\n");

    //memset
    printf("*****FT_MEMSET**\n");
    printf("Before ft_memset = %s\n", memsetStr);
    memset(memsetStr, memsetInt, 20);
    printf("After memset = %s\n", memsetStr);
    ft_memset(memsetStr, memsetInt, 20);
    printf("After ft_memset = %s\n", memsetStr);
    printf("**********************************************\n");

    //memchr
    printf("*****FT_MEMCHR**\n");
    printf("Before ft_memchr = %s\n", memchrStr);
    printf("String after |%c| is: |%s|\n", memchrInt, memchr(memchrStr, memchrInt, 20));
    printf("String after |%c| is: |%s|\n", memchrInt, ft_memchr(memchrStr, memchrInt, 20));
    printf("**********************************************\n");

    //memcmp
    printf("*****FT_MEMCMP**\n");
    printf("Before ft_memcmp = '%s' and '%s'\n", memcmpStr1, memcmpStr2);
    printf("After memcmp = %d\n", memcmp(memcmpStr1, memcmpStr2, 11));
    printf("After ft_memcmp = %d\n", ft_memcmp(memcmpStr1, memcmpStr2, 11));
    printf("**********************************************\n");

    //strchr
    printf("*****FT_STRCHR**\n");
    printf("String: '%s' , char to locate: '%c', result:\n", strchrStr, (char)strchrInt);
    printf("Location with strchr = %s\n", strchr(strchrStr, strchrInt));
    printf("Location with ft_strchr = %s\n", ft_strchr(strchrStr, strchrInt));
    printf("**********************************************\n");

    //strrchr
    printf("*****FT_STRRCHR**\n");
    printf("String: '%s' , char to locate: '%c', result:\n", strchrStr, (char)strchrInt);
    printf("Location with strrchr = %s\n", strrchr(strchrStr, strchrInt));
    printf("Location with ft_strrchr = %s\n", ft_strrchr(strchrStr, strchrInt));
    printf("**********************************************\n");

    //strstr
    printf("*****FT_STRSTR**\n");
    printf("String: '%s' , needle 1: '%s', needle 2: %s:\n", strstrHay, strstrNe1, strstrNe2);
    printf("strstr with needle 1 = %s\n", strstr(strstrHay, strstrNe1));
    printf("ft_strstr with needle 1 = %s\n", ft_strstr(strstrHay, strstrNe1));
    printf("strstr with needle 2 = %s\n", strstr(strstrHay, strstrNe2));
    printf("ft_strstr with needle 2 = %s\n", ft_strstr(strstrHay, strstrNe2));
    printf("**********************************************\n");

    //strnstr
    printf("*****FT_STRNSTR**\n");
    printf("String: '%s' , needle 1: '%s'\n", strstrHay, strstrNe1);
    printf("strnstr with needle 1 and n = 1: %s\n", strnstr(strstrHay, strstrNe1, 1));
    printf("ft_strnstr with needle 1 and n = 1: %s\n", ft_strnstr(strstrHay, strstrNe1, 1));
    printf("strnstr with needle 1 and n = 2: %s\n", strnstr(strstrHay, strstrNe1, 2));
    printf("ft_strnstr with needle 1 and n = 2: %s\n", ft_strnstr(strstrHay, strstrNe1, 2));
    printf("strnstr with needle 1 and n = 6: %s\n", strnstr(strstrHay, strstrNe1, 6));
    printf("ft_strnstr with needle 1 and n = 6: %s\n", ft_strnstr(strstrHay, strstrNe1, 6));
    printf("strnstr with needle 1 and n = 7: %s\n", strnstr(strstrHay, strstrNe1, 7));
    printf("ft_strnstr with needle 1 and n = 7: %s\n", ft_strnstr(strstrHay, strstrNe1, 7));
    printf("**************\n");
    printf("String: '%s' , needle 2: '%s'\n", strstrHay, strstrNe2);
    printf("strnstr with needle 2 and n = 1: %s\n", strnstr(strstrHay, strstrNe2, 1));
    printf("ft_strnstr with needle 2 and n = 1: %s\n", ft_strnstr(strstrHay, strstrNe2, 1));
    printf("strnstr with needle 2 and n = 2: %s\n", strnstr(strstrHay, strstrNe2, 2));
    printf("ft_strnstr with needle 2 and n = 2: %s\n", ft_strnstr(strstrHay, strstrNe2, 2));
    printf("**********************************************\n");

    //strcat
    printf("*****FT_STRCAT**\n");
    printf("String dst: '%s' , String src: '%s'\n", strcatDst, strcatSrc);
    strcat(strcatDst, strcatSrc);
    printf("After strcat %s\n", strcatDst);
    ft_strcat(strcatDst, strcatSrc);
    printf("After ft_strcat %s\n", strcatDst);
    printf("**********************************************\n\n");

    //strncat
    printf("*****FT_STRNCAT**\n");
    printf("String dst: '%s' , String src: '%s'\n", strncatDst, strncatSrc);
    strncat(strncatDst, strncatSrc, 6);
    printf("After strncat %s\n", strncatDst);
    ft_strncat(strncatDst, strncatSrc, 6);
    printf("After ft_strncat %s\n", strncatDst);
    printf("**********************************************\n\n");

    //strlcat
    printf("*****FT_STRNLCAT**\n");
    printf("String dst: '%s' , String src: '%s', size_t: %i\n", strlcatDst, strlcatSrc, 20);
    strlcat(strlcatDst, strlcatSrc, 20);
    printf("After strlcat: %s\n", strlcatDst);
    printf("String dst: '%s' , String src: '%s', size_t: %i\n", strlcatDst, strlcatSrc, 27);
    ft_strlcat(strlcatDst, strlcatSrc, 27);
    printf("After ft_strncat: %s\n", strlcatDst);
    printf("**********************************************\n");

    return (0);
}
