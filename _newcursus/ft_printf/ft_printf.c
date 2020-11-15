/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 01:31:58 by mhuerta           #+#    #+#             */
/*   Updated: 2020/11/14 20:37:59 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
  Esta es la función MAESTRA 🤓, la que llama al resto de funciones
  1. Recibe *format como primer argumento y otros ...
  2. Se declaran e inicializan valores:
    - ret (retorno, que sirve como señal de éxito o error, como también para contabilizar
      la cantidad de caracteres)
    - attr (estructura de tipo t_fmt, en la que se almacenaran flags, width, precision)
  3. Itera por cada caracter de *format y al encontrar un '%' llama a otras funciones
    - inicializa los valores de los campos con `ptf_initfields`
    - identifica cual de los campos sigue al %  con `pft_setfields`  
*/

int ft_printf(char const *format, ...)
{
  //2.
  int ret;
  t_fields attr;
  va_list args_list;

  ret = 0;
  va_start(args_list, format);
  //3.
  while (*format)
  {
    if (*format == '%')
    {
      format++;
      format += pft_putfields(&attr, format, args_list);
      if (*format == '\0')
				break ;
			ret += attr.q;
    }
    else
      ret += ft_putcharcounter(*format);
    format++;
  }

  va_end(args_list);
  return (ret);
}