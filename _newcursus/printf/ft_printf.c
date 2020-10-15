/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 01:31:58 by mhuerta           #+#    #+#             */
/*   Updated: 2020/10/15 00:01:16 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
  1. Revisa el "specifier" y llama a la función correspondiente.
  2. Retorna la cantidad de caracteres recorridos/leidos.

  A implementar: -1 cuando no encuentra ninguno??
*/

int ft_putspecifier(t_fields *fields, va_list args_list)
{
  int ret;

  ret = 0;
  if (fields->spec == 'c')
    ret += ptf_char(fields, args_list);
  return (ret);
}

void  pft_setflags(t_fields *attr, const char fmt){
    if (fmt == '-')
    {
      attr->fNegative = 1;
      attr->fZero = 0;
    } else if (fmt == '*'){
      attr->wildcard = 1;
    } else if(fmt == '0'){
        attr->fZero = 1;
    }
}
/* 
  Busca los valores reales de los campos (fields) flags, width y precision.
  y los coloca.
*/
void pft_setfields(t_fields *attr, const char *fmt)
{
  int   n;

  n = 0;
  while (*fmt == '-' || *fmt == '*' || ft_isdigit(*fmt))
  {
    pft_setflags(attr, *fmt);
    if (ft_isdigit(*fmt))
    { 
      //parte de atoi
      while (ft_isdigit(*fmt))
      {
        n = n * 10 + (*fmt - '0');
        fmt++;
        attr->q++;
      }
      
      attr->width = n;
      //printf("width %d: ", attr->width);
    } else{
      attr->q++;
      fmt++;
    }
  }
  attr->spec = *fmt;
  //printf("spec: %c\n", attr->spec);
  attr->q++;
  
}

/* 
  Inicializa los valores de los campos (fields) flags, width y precision.
  Para flags solo se consideran 0, -
*/
void ptf_initfields(t_fields *attr)
{
  attr->fNegative = 0;
  attr->fZero = 0;
  attr->wildcard = 0;
  attr->precision = -1;
  attr->width = 0;
  attr->spec = '\0';
  attr->q = 0;
}

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
      ptf_initfields(&attr);
      format++;
      pft_setfields(&attr, format);
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
}