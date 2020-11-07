/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 18:19:01 by mhuerta           #+#    #+#             */
/*   Updated: 2020/11/07 16:34:08 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    ptf_tst_char(){
    /* ******************************  CHAR  ************************************* */
    /*
    Para imprimir un caracter, este puede tener las sgtes combinaciones:

        - : justificado a la izquierda, con el 'width' brindado
        * : cuando el 'width' no es especificado, pero se brinda como un entero,
            precediendo a 'c'
    *******************************************************************************
    
        | Case  | format        | args_list       | output expected        |
        | --------------------- | --------------- | ---------------------- |
        | 0     | %c %-4cM      | '?', 42         | ? *   M                | OK
        | 1     | %c %c         | '?', 42         | ? *                    | OK
        | 2     | %-3c.         | 'm'             | m  .                   | OK
        | 3     | %-11c.        | 'm'             | m          .           | OK
        | 4     | %*c           | 5, 'm'          |     m.                 | OK
        | 5     | %-*c.         | 5, 'm'          | m    .                 | OK
        | 6     | %03c.         | 'f'             | 00f.                   | OK

    ********************************************************************************
    */

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
    ft_printf("ft_printf ~ %03c.\n\n",'f');
 

    printf("************ EXTRA TESTS x CHAR ************\n");
    printf("**** case 7: %%1c%%2c%%3c%%4c%%1c%%2c values given: ''\"',  '!', '\"', '#', '$', '%%' \n");
    printf("printf    ~ %1c%2c%3c%4c%1c%2c\n", '\"',  '!','\"', '#', '$', '%');
    ft_printf("ft_printf ~ %1c%2c%3c%4c%1c%2c\n", '\"', '!', '\"', '#', '$', '%');
    printf("\n");
    printf("******************************\n");
}

void    ptf_tst_str(){
    printf("********************************************\n");
    printf("*************** TESTS x STR ***************\n");
    printf("********************************************\n");

    printf("**** case 0: %%s %%s values given: 'hey my name is', 'Melissa' **\n");
    printf ("sysprintf    ~ %s %s\n", "hey my name is", "Melissa");
    ft_printf ("ft_printf    ~ %s %s\n\n", "hey my name is", "Melissa");

    printf("**** case 1: %%9s values given: 'Melissa' **\n");
    printf ("sysprintf    ~ %9s\n", "Melissa");
    ft_printf ("ft_printf    ~ %9s\n\n", "Melissa");

    printf("**** case 2: %%9s %%3s values given: 'Melissa', 'H' **\n");
    printf ("sysprintf    ~ %9s %3s\n", "Melissa", "H");
    ft_printf ("ft_printf    ~ %9s %3s\n\n", "Melissa", "H");
    
    printf("**** case 3: %%-8s values given: 'Meli' **\n");
    printf ("sysprintf    ~ %-8s\n", "Meli");
    ft_printf ("ft_printf    ~ %-8s\n\n", "Meli");

    printf("**** case 4: %%-0s values given: 'Meli' **\n");
    printf ("sysprintf    ~ %-0s\n", "Meli");
    ft_printf ("ft_printf    ~ %-0s\n\n", "Meli");

    printf("**** case 5: %%*s values given: '6', 'Meli'**\n");
    printf ("sysprintf    ~ %*s\n", 6, "Meli");
    ft_printf ("ft_printf    ~ %*s\n\n", 6, "Meli"); 

    printf("**** case 6: %%5.3s values given: 'banana' **\n");
    printf ("sysprintf    ~ %5.3s\n", "banana");
    ft_printf ("ft_printf    ~ %5.3s\n\n", "banana"); 
    
    printf("**** case 7: %%.3s values given: 'hello' **\n");
    printf ("sysprintf    ~ %.3s\n", "hello");
    ft_printf ("ft_printf    ~ %.3s\n\n", "hello"); 

    printf("**** case 8: %%10.s values given: 'NULL' **\n");
    printf ("sysprintf    ~ %10.s\n", NULL);
    ft_printf ("ft_printf    ~ %10.s\n\n", NULL);

    printf("**** case 9: %%.*s values given: -3, 0 **\n");
    printf ("sysprintf    ~ %.*s\n", -3, NULL);
    ft_printf ("ft_printf    ~ %.*s\n\n", -3, NULL);
        
    printf("**** case 10: %%s values given: 'testing testing' **\n");
    printf ("sysprintf    ~ %s\n", "testing testing");
    ft_printf ("ft_printf    ~ %s\n\n", "testing testing");
    
}


/*
 **** MAIN TO TEST 🍙 ****
*/

int main(int ac, char const  **av){
    
    /* ptf_tst_char();
    ptf_tst_str(); */
    ptf_tst_str();

    //flags: #-+`'0][width][precision][format character]
    
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