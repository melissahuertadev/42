/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 01:31:58 by mhuerta           #+#    #+#             */
/*   Updated: 2020/11/01 16:52:02 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
/* 
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

    [flags: #-+`'0][width][precision][format character]
*/
/*
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
      //analyze format ~ ret
      ptf_initfields(&attr);
      format++;
      pft_setfields(&attr, format, args_list);
      ret += ft_putspecifier(&attr, args_list);
     // printf("format: %c\n", *format);
      format = format + attr.q;
     // printf("format: %c\n", *format);
    }
    else
    {
      ft_putchar(*format);
      ret++;
      format++;
    }
  }
  va_end(args_list);
  return (ret);
} */