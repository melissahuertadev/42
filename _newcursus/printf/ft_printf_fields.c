/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fields.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:01:43 by mhuerta           #+#    #+#             */
/*   Updated: 2020/11/01 16:54:35 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/* /* 
  Inicializa los valores de los campos (fields) flags, width y precision.
  Para flags solo se consideran 0, -

void ptf_initfields(t_fields *attr)
{
  attr->fNegative = 0;
  attr->fZero = 0;
  attr->width = 0;
  attr->precision = -1;
  attr->wildcard = 0;
  attr->spec = '\0';
  attr->q = 0;
}

void pft_setfields(t_fields *attr, const char *fmt, va_list args_list)
{
  int   n;

  n = 0;
  while (*fmt == '-' || *fmt == '*' || ft_isdigit(*fmt))
  {
    pft_setflags(attr, *fmt, args_list);
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
    } else {
      attr->q++;
      fmt++;
    }
  }
  attr->spec = *fmt;
  //printf("spec: %c\n", attr->spec);
  attr->q++;
  
}

void  pft_setflags(t_fields *attr, const char fmt,  va_list args_list){
    if (fmt == '-')
    {
      attr->fNegative = 1;
      //attr->fZero = 0;
    } else if(fmt == '0'){
      attr->fZero = 1;
    } else if (fmt == '*'){
      //attr->wildcard = 1;
      attr->width = va_arg(args_list, int);
    } 
}


  1. Revisa el "specifier" y llama a la función correspondiente.
  2. Retorna la cantidad de caracteres recorridos/leidos.

  A implementar: -1 cuando no encuentra ninguno??


int ft_putspecifier(t_fields *fields, va_list args_list)
{
  int ret;

  ret = 0;
  if (fields->spec == 'c')
    ret += ptf_char(fields, args_list);
  if(fields->spec == 's'){
    ret += ptf_str(fields, args_list);
  }
    
  return (ret);
} */