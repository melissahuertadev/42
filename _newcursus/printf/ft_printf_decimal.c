/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 11:18:20 by mhuerta           #+#    #+#             */
/*   Updated: 2020/11/10 01:40:06 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"



/* ******************************  DCM  ************************************* */
/*

  *******************************************************************************
  
	| Case  | format        | args_list       | output expected |
	| --------------------- | --------------- | --------------- |
  | 0     | %d            | 31              | `31`            | OK
  | 1     | %d            | -21             | `-21`           | OK
  | 2     | %7d           | 42              | `     42`       | OK
  | 3     | %-6d          | 2               | `29    `        | OK
  | 4     | %.5d          | 3               | `00003`         |
  | 5     | %.5d          | -3              | `-00003`        |

  ********************************************************************************
*/

int ptf_dcm(t_fields *fields, va_list args_list){
  int   dec;
  int   len;
  int   qSpaces;
  int   qZeros;

  dec = va_arg(args_list, int);
  len = ft_intlen(dec);
  qSpaces = -1;
  qZeros = -1;

  if(dec == 0 && fields->precision == 0){
    pft_spaces(fields->width + 1, ' ');
    return fields->width;
  } else if(fields->width > 0 && fields->precision > 0){
    if(dec < 0){
      len--;
      fields->width--;
    }
    qZeros = fields->precision - len;
    if (qZeros > 0)
      qSpaces = fields->width - len - qZeros;
    else 
      qSpaces = fields->width - len;
  } else if (fields->width > 0){
    if(fields->fZero){
      qZeros = fields->width - len;
    } else 
      qSpaces = fields->width - len;
  } else if (fields->precision > 0){
    if(dec < 0){
      len--;
    }
    qZeros = fields->precision - len;
  }
  if(fields->fMinus == 0){
    pft_spaces(qSpaces + 1, ' ');
  }
  if(dec < 0 && dec != -2147483648){
    dec *= -1;
    ft_putchar('-');
  }
  pft_spaces(qZeros + 1, '0');
  ft_putnbr(dec);
  if(fields->fMinus == 1){
    pft_spaces(qSpaces + 1, ' ');
  }
  return len;
}