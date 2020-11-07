/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 19:18:57 by mhuerta           #+#    #+#             */
/*   Updated: 2020/11/07 16:35:32 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"



/* ******************************  STR  ************************************* */
/*
  Para imprimir un caracter, este puede tener las sgtes combinaciones:

	- : justificado a la izquierda, con el 'width' brindado
	* : cuando el 'width' no es especificado, pero se brinda como un entero,
		precediendo a 'c'
  *******************************************************************************
  
	| Case  | format        | args_list                   | output expected        |
	| --------------------- | --------------------------- | ---------------------- |
  | 0     | %s %s         | "hey my name is", "Melissa" | hey my name is Melissa | OK
  | 1     | %9s           | "Melissa"                   | `  Melissa`            | OK
  | 2     | %9s %3s       | "Melissa", "H"              | `  Melissa   H`        | OK
  | 3     | %-8s          | "Meli"                      | `Meli    `             | OK
  | 4     | %-0s          | "Meli"                      | `Meli`                 | OK
  | 5     | %*s           | 6, "Meli"                   | `  Meli`               | OK
  | 6     | %5.3s         | "banana"                    | `  ban`                | OK
  | 7     | %.3s          | "hello"                     | `hel`                  | OK
  | 8     | %10.s         | NULL                        | `          `           | OK
  | 9     | %.*s          | -3, NULL                    | `(null`                | OK
  | 10    | %s            | "testing testing"           | `testing testing`      | OK
  ********************************************************************************
*/
    
int ptf_str(t_fields *fields, va_list args_list){
  int len;
  int new_len;
  char *str;
  char  space;
  int   ret;
  
  str = va_arg(args_list, char *);
  if (str == NULL){
    str = "(null)";
  }
		
  len = ft_strlen(str);
  new_len = (fields->precision >= 0 && fields->precision < len) ? fields->precision : len;
  space = fields->fZero == 1 ? '0' : ' ';
  ret = 0;
  if(fields->width > new_len){
    if(fields->fNegative != 1){
      ret += pft_spaces(fields->width - new_len + 1, space);
      ft_putstr((const char *)ft_strsub(str, 0, new_len));
    } else{
      ft_putstr((const char *)ft_strsub(str, 0, new_len));
      ret += pft_spaces(fields->width - new_len + 1, space);
    }
  } else
    ft_putstr((const char *)ft_strsub(str, 0, new_len));
    
  ret += new_len;
  return ret;
}

int ptf_char(t_fields *fields, va_list args_list)
{
  int ret;
  char c;
  char  space;

  ret = 0;
  space = ' ';
  c = va_arg(args_list, int);

  if (fields->fNegative == 1)
  {
    //imprime el caracter seguido de la cantidad de espacios especificados
    space = fields->fZero == 1 ? '0' : ' ';
    ft_putchar(c);
    ret += pft_spaces(fields->width, space);

  }
  else
  {
    //imprime la cantidad de espacios especificados seguido del caracter
    space = fields->fZero == 1 ? '0' : ' ';
    ret += pft_spaces(fields->width, space);
    ft_putchar(c);
  }
  ret++;
  return (ret);
}


int pft_spaces(int cant, char c)
{
  int ret;

  ret = 0;
  while (--cant > 0)
  {
    ft_putchar(c);
    ret++;
  }
  
  return (ret);
}