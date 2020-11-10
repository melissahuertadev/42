/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fields.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:01:43 by mhuerta           #+#    #+#             */
/*   Updated: 2020/11/09 20:29:55 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
  [flags: #-+`'0][width][precision][format character]
*/

int pft_putfields(t_fields *attr, const char *fmt, va_list args_list){
    int ret;

    ret = 0;
    ptf_initfields(attr);
    ret += pft_setfields(attr, fmt, args_list);
    attr->q += ft_putspecifier(attr, args_list);
    
    return ret;
}


/* 
  Inicializa los valores de los campos (fields) flags, width y precision.
  Para flags solo se consideran 0, -
*/
void ptf_initfields(t_fields *attr)
{
  attr->fMinus = 0;
  attr->fZero = 0;
  attr->width = 0;
  attr->precision = -1;
  attr->wildcard = 0;
  attr->spec = '\0';
  attr->qZeros = -1;
  attr->qSpaces = -1;
  attr->q = 0;
}


//[flags: -0][width][precision][format character]
int pft_setfields(t_fields *attr, const char *fmt, va_list args_list)
{
  int spec_counter;

  spec_counter = 0;
  
  while (*fmt == '-' || *fmt == '.' || *fmt == '*' || ft_isdigit(*fmt)){
    pft_setflags(attr, *fmt, args_list);
    fmt++;
    spec_counter++;
  }
  
  attr->spec = *fmt;
  return spec_counter;
}

void  pft_setflags(t_fields *attr, const char fmt,  va_list args_list){
   if (fmt == '-')
    {
      attr->fMinus = 1;
    }
    else if(fmt == '0' && attr->width == 0){
        attr->fZero = (attr->fMinus == 1) ? 0 : 1;
    } else if (fmt == '.'){
      attr->precision = 0;  
    } else if (ft_isdigit(fmt)) {
      if(attr->precision == -1){
        attr->width = (attr->width * 10) + (fmt - '0');
      } else {
        attr->precision = (attr->precision * 10) + (fmt - '0');
      }
    } else if (fmt == '*'){
      attr->wildcard = 1;
      if(attr->precision == 0){
         attr->precision = va_arg(args_list, int);
      } else
          attr->width = va_arg(args_list, int);
    }
}

/*
  1. Revisa el "specifier" y llama a la función correspondiente.
  2. Retorna la cantidad de caracteres recorridos/leidos.
*/

int ft_putspecifier(t_fields *fields, va_list args)
{
  int print_counter;

  print_counter = 0;
  if (fields->spec == 'c' || fields->spec == '%')
    print_counter += ptf_char(fields, fields->spec == 'c' ? va_arg(args, int) : '%');
  if(fields->spec == 's')
    print_counter += ptf_str(fields, va_arg(args, char *));
  if(fields->spec == 'd' || fields->spec == 'i')
    print_counter += ptf_dcm(fields, args);
  if(fields->spec == 'u')
    print_counter += ptf_uns_dcm(fields, va_arg(args, unsigned int));
  if(fields->spec == 'x' || fields->spec == 'X')
    print_counter += ptf_uns_hexa(fields, va_arg(args, unsigned int));
  
  //if(fields->spec == 'p')
    
  return (print_counter);
}