/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 19:18:57 by mhuerta           #+#    #+#             */
/*   Updated: 2020/10/15 00:03:45 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
	| 2     | %-3c          | 'm'             | m  .                   | OK
	| 3     | %-11c         | 'm'             | m          .           | OK
	| 4     | %*c           | 5, 'm'          |     m.                 | OK
	| 5     | %-*c          | 5, 'm'          | m    .                 | OK
	| 6     | %03c.         | 'f'             | 00f.                   | OK

  ********************************************************************************
*/


int ptf_char(t_fields *fields, va_list args_list)
{
  int ret;
  char c;
  char  space;

  ret = 0;
  space = ' ';
  c = va_arg(args_list, int);
  
  //si es *
  if (fields->wildcard == 1){
	fields->width = c;
	c = va_arg(args_list, int);
	//printf("width %d\n", fields->width);
  }
  
  //
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