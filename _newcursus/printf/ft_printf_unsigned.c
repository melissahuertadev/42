/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 11:04:13 by mhuerta           #+#    #+#             */
/*   Updated: 2020/11/09 20:38:22 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ptf_uns_dcm(t_fields *fields, unsigned int dec) {
  int   len;

  len = ft_uintlen(dec, 10);

  //getting the values for 0 and ' '
  if(dec == 0 && fields->precision == 0){
    pft_spaces(fields->width + 1, ' ');
    return fields->width;
  } else 
    pft_setpadding(fields, len);

  //printing
  if(fields->fMinus == 0){
    pft_spaces(fields->qSpaces + 1, ' ');
  }
  pft_spaces(fields->qZeros + 1, '0');
  ft_putunbr(dec);
  if(fields->fMinus == 1){
    pft_spaces(fields->qSpaces + 1, ' ');
  }
  
  return len;
}


int ptf_uns_hexa(t_fields *fields,  unsigned int dec) {
  char  *hexadec;
  int   len;

  hexadec = ft_utoa_hexa(dec, fields->spec);
  len = ft_strlen(hexadec);
  
  //getting the values for 0 and ' '
  if(dec == 0 && fields->precision == 0){
    pft_spaces(fields->width + 1, ' ');
    return fields->width;
  } else 
    pft_setpadding(fields, len);
  
  //printing
  if(fields->fMinus == 0){
    pft_spaces(fields->qSpaces + 1, ' ');
  }
  pft_spaces(fields->qZeros + 1, '0');
  ft_putstr(hexadec);
  if(fields->fMinus == 1){
    pft_spaces(fields->qSpaces + 1, ' ');
  }
  return len;
}

void pft_setpadding(t_fields *fields, int len){
  fields->qSpaces = -1;
  fields->qZeros = -1;
  
  if(fields->width > 0 && fields->precision > 0){
    fields->qZeros = fields->precision - len;
    if (fields->qZeros > 0)
      fields->qSpaces = fields->width - len - fields->qZeros;
    else 
      fields->qSpaces = fields->width - len;
  } else if (fields->width > 0){
    if(fields->fZero){
      fields->qZeros = fields->width - len;
    } else 
      fields->qSpaces = fields->width - len;
  } else if (fields->precision > 0){
    fields->qZeros = fields->precision - len;
  }
}