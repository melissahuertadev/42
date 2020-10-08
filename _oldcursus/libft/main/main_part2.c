#include "libft.h"
#include <stdio.h>

/*
**gcc main_part2.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strlen.c
**ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_weirdchar.c
**ft_putchar.c ft_putnbr.c ft_strequ.c ft_strsub.c ft_strnequ.c ft_strjoin.c
**ft_strcat.c ft_strcpy.c ft_itoa.c ft_genswap.c ft_intlen.c ft_memcpy.c
*/
  
int	main()
{	
	/* *** memalloc *** */
    size_t  memallocSiz = 5;

    printf("*****FT_MEMALLOC**\n");
    printf("size_t = %zu\n", memallocSiz);
    printf("After ft_memalloc = %s\n", ft_memalloc(memallocSiz));
    printf("**********************************************\n\n");

    /* *** memdel  *** */
    void    *memdelStr = "This sentence will be - memdel";
    void    **memdelPtr = &memdelStr;
       
    printf("*****FT_MEMDEL**\n");
    printf("Before ft_memdel = %s\n", (char *)memdelStr);
    memdelStr = (void *)malloc(sizeof(memdelStr));
    ft_memdel(memdelPtr);
    printf("After ft_memdel = %s\n", (char *)memdelStr);
    printf("**********************************************\n\n");

    /* *** strnew *** */
    size_t  strnewSiz = 31;

    printf("*****FT_STRNEW**\n");
    printf("Before ft_strnew = %zu\n", strnewSiz);
    printf("After ft_strnew = %zu and char * = %s\n", strnewSiz, ft_strnew(strnewSiz));
    printf("**********************************************\n\n");

    /* *** strdel  *** */
    char    *strdelStr = "This sentence will be - strdel";
    char    **strdelPtr = &strdelStr;

    printf("*****FT_STRDEL**\n");
    printf("Before ft_strdel = %s\n", strdelStr);
    strdelStr = (void *)malloc(sizeof(strdelStr));
    ft_strdel(strdelPtr);
    printf("After ft_strdel = %s\n", strdelStr);
    printf("**********************************************\n\n");

    /* *** strclr *** */
    char    strclrStr[] = "String to be cleared";   
    
    printf("*****FT_STRCLR**\n");
    printf("Before ft_strclr = %s\n", strclrStr);
    ft_strclr(strclrStr);
    printf("After ft_strclr = %s\n", strclrStr);
    printf("**********************************************\n\n");

    /* *** striter *** */
    char    striterStr[] = "Print this";
	void    (*fStriter)(char*);
    fStriter = &ft_strclr;
    
    printf("*****FT_STRITER**\n");
    printf("Before ft_striter (strclr) = %s\n", striterStr);
    ft_striter(striterStr, fStriter);
    printf("After ft_striter (strclr) = %s\n", striterStr);
    printf("**********************************************\n\n");

    /* *** striteri *** */
    char    striteriStr[] = "abc";
	void    (*fStriteri)(unsigned int, char*);
    fStriteri = &ft_weirdchar;

    printf("*****FT_STRITERI**\n");
    printf("Before ft_striteri  = %s\n", striteriStr);
    ft_striteri(striteriStr, fStriteri);
    printf("**********************************************\n\n");

    /* *** strequ *** */
    char    const strquStr1[] = "String 1";
    char    const strquStr2[] = "String 2";
    printf("*****FT_STREQU**\n");
    printf("Compare '%s' and '%s'\n", strquStr1, strquStr2);
    printf("result: %i\n", ft_strequ(strquStr1, strquStr2));
    printf("Compare '%s' and '%s'\n", strquStr1, strquStr1);
    printf("result: %i\n", ft_strequ(strquStr1, strquStr1));
    printf("**********************************************\n\n");

    /* *** strnequ *** */
    char    const strnequStr1[] = "String N 1";
    char    const strnequStr2[] = "St A 2";
    printf("*****FT_STRNEQU**\n");
    printf("Compare '%s' and '%s', using size: 2\n", strnequStr1, strnequStr2);
    printf("result: %i\n", ft_strnequ(strnequStr1, strnequStr2, 2));
    printf("Compare '%s' and '%s', using size: 3\n", strnequStr1, strnequStr2);
    printf("result: %i\n", ft_strnequ(strnequStr1, strnequStr2, 3));
    printf("**********************************************\n\n");

    /* *** strsub *** */
    char    const *strsubStr1 = "Original string";
    char    const *strsubStr2 = "0123456789";
    unsigned    int strsubInt = 3;
    size_t  strsubLen = 8;
    printf("*****FT_STRSUB**\n");
    printf("String: '%s' | index: '%i' | size: '%zu'\n", strsubStr1, strsubInt, strsubLen);
    printf("result: %s\n", ft_strsub(strsubStr1, strsubInt, strsubLen));
    printf("String: '%s' | index: '%i' | size: '%d'\n", strsubStr2, 7, 9);
    printf("result: %s\n", ft_strsub(strsubStr2, 7, 9));
    printf("**********************************************\n\n");

    
    /* *** strjoin *** */
    char    const *strjoinStr1 = "Prefix 42";
    char    const *strjoinStr2 = "Sufix ++89";

    printf("*****FT_STRJOIN**\n");
    printf("String 1: '%s' | String 2: '%s'\n", strjoinStr1, strjoinStr2);
    printf("result: %s\n", ft_strjoin(strjoinStr1, strjoinStr2));
    printf("**********************************************\n\n");

    /*
strtim
char * ft_strtrim(char const *s)
strsplit 
char ** ft_strsplit(char const *s, char c)*/

    /* *** itoa *** */
    
    int itoaInt1 = 914;
    int itoaInt2 = -589;
    
    printf("*****FT_ITOA**\n");
    printf("dig %i\n", itoaInt1);
    printf("converted to string: %s\n", ft_itoa(itoaInt1));
    printf("---\n");
    printf("dig %i\n", itoaInt2);
    printf("converted to string: %s\n", ft_itoa(itoaInt2));

    return (0);
}
