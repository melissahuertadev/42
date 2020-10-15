/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 18:19:01 by mhuerta           #+#    #+#             */
/*   Updated: 2020/10/15 00:02:10 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//void    ptf_tst_num(){}
//void    ptf_tst_str(){}


void    ptf_tst_char(){
    printf("********************************************\n");
    printf("*************** TESTS x CHAR ***************\n");
    printf("********************************************\n");
    
    printf("**** case 0: %%c %%-4cM, values given: ? 42 **\n");
    printf ("printf    ~ %c %-4cM\n", '?', 42);
    ft_printf ("ft_printf ~ %c %-4cM\n\n", '?', 42);

    printf("**** case 1: %%c %%c, values given: ? 42 ****\n");
    printf ("printf    ~ %c %c\n", '?', 42);
    ft_printf ("ft_printf ~ %c %c\n\n", '?', 42);
    
    printf("**** case 2: %%-3c., values given 'm' *******\n");
    printf("printf    ~ %-3c.\n", 'm');
    ft_printf("ft_printf ~ %-3c.\n\n", 'm');
    
    printf("**** case 3: %%-11celi, values given 'm' ****\n");
    printf("printf    ~ %-11celi\n", 'm');
    ft_printf("ft_printf ~ %-11celi\n\n", 'm');
    
     
    printf("**** case 4: %%*c. with * = 5 *************\n");
    printf("printf    ~ %*c.\n", 5, 'm');
    ft_printf("ft_printf ~ %*c.\n\n", 5, 'm');
    
    printf("**** case 5: %%-*c. with * = 5 ************\n");
    printf("printf    ~ %-*c.\n", 5, 'm');
    ft_printf("ft_printf ~ %-*c.\n\n", 5, 'm');

    printf("**** case 6: %%03c. values given: 'f' ******\n");
    printf("printf    ~ %03c.\n", 'f');
    ft_printf("ft_printf ~ %03c.\n",'f');
    printf("\n\n");
}


/*
 **** MAIN TO TEST 🍙 ****
*/

int main(int ac, char const  **av){
    ptf_tst_char();
    printf("********************************************\n");
    printf("************ EXTRA TESTS x CHAR ************\n");
    printf("********************************************\n");
   
    printf("**** case 7: %%1c%%2c%%3c%%4c%%1c%%2c values given: ''\"',  '!', '\"', '#', '$', '%%' \n");
    printf("printf    ~ %1c%2c%3c%4c%1c%2c\n", '\"',  '!','\"', '#', '$', '%');
    ft_printf("ft_printf ~ %1c%2c%3c%4c%1c%2c\n", '\"', '!', '\"', '#', '$', '%');
    printf("\n");
    printf("******************************\n");
    
    /*
    printf("********************************************\n");
    printf("*************** TESTS x CHAR ***************\n");
    printf("********************************************\n");
    printf ("printf ~ string: %s \n", "Yellow sunshine");
    ft_printf ("ft_printf ~ string: %s \n", "Yellow sunshine");
    printf ("***** \n");
    */
   /*
   printf ("printf ~ string: %s \n", "Yellow sunshine");
    ft_printf ("ft_printf ~ string: %s \n", "over the rainbow");
    printf ("***** \n");*/
    
    /*
    printf ("Decimals: %d %ld\n", 1977, 650000L);
    ft_printf ("Decimals: %d %ld\n", 1977, 650000L);
    printf ("***** \n");
    printf ("Preceding with blanks: %10d \n", 1977);
    ft_printf ("Preceding with blanks: %10d \n", 1977);
    printf ("***** \n");
    printf ("Preceding with zeros: %010d \n", 1977);
    ft_printf ("Preceding with zeros: %010d \n", 1977);
    printf ("***** \n");
    printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
    ft_printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
    printf ("***** \n");
    printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
    ft_printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
    printf ("***** \n");
    printf ("Width trick: %*d \n", 5, 10);
    ft_printf ("Width trick: %*d \n", 5, 10);
    printf ("***** \n");
    */


    return 0;
}