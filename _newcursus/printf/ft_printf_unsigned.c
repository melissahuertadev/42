/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 11:04:13 by mhuerta           #+#    #+#             */
/*   Updated: 2020/11/09 02:19:59 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ptf_uns_dcm(t_fields *fields, unsigned int dec){
  int   len;
  int   qSpaces;
  int   qZeros;

  len = ft_uintlen(dec);
  qSpaces = -1;
  qZeros = -1;

  if(dec == 0 && fields->precision == 0){
    pft_spaces(fields->width + 1, ' ');
    return fields->width;
  } else if(fields->width > 0 && fields->precision > 0){
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
    qZeros = fields->precision - len;
  }
  if(fields->fMinus == 0){
    pft_spaces(qSpaces + 1, ' ');
  }
  pft_spaces(qZeros + 1, '0');
  ft_putunbr(dec);
  if(fields->fMinus == 1){
    pft_spaces(qSpaces + 1, ' ');
  }
  return len;
}