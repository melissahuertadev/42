/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 11:18:20 by mhuerta           #+#    #+#             */
/*   Updated: 2020/11/07 20:43:49 by mhuerta          ###   ########.fr       */
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
  int dec;
  int len;
  char  space;

  dec = va_arg(args_list, int);
  len = ft_intlen(dec);  
  space = (fields->fZero == 1) ? '0' : ' ';
  //printf("number len %d\n", len);
  
  //&& flags->point >= flags->width)
  if(fields->precision > len){
    if(dec < 0){
      dec *= -1;
      ft_putchar('-');
      fields->precision++;
    }
    pft_spaces(fields->precision - len + 1, '0');
    ft_putnbr(dec);
  } else if(fields->width > len){
    if(fields->fNegative != 1){
      pft_spaces(fields->width - len + 1, space);
      ft_putnbr(dec);
    } else{
      ft_putnbr(dec);
      pft_spaces(fields->width - len + 1, space);
    }
  }
  
  /* if(fields->width > len){
    if(fields->fNegative != 1){
      pft_spaces(fields->width - len + 1, space);
      ft_putnbr(dec);
    } else{
      ft_putnbr(dec);
      pft_spaces(fields->width - len + 1, space);
    }
  } else if(fields->precision > len){
    pft_spaces(fields->precision - len + 1, space);
    ft_putnbr(dec);
  }  */
  else
    ft_putnbr(dec);
  
  /*
  
	int len;
	int	number;
	int count;

	ft_printf_star(flags, args);
	number = va_arg(args, int);
	len = ft_numlen(number);
	count = 0;
	if (flags->point == 0 && number == 0)
		count += ft_putflags(flags->width, ' ');
	else if (flags->len == 0 || (len >= flags->width && len > flags->point))
		count += ft_putnbr(number);
	else if (flags->point >= len && flags->point >= flags->width)
		count += ft_printf_da(flags, len, number);
	else if (flags->width >= len && len > flags->point)
	{
		if (flags->minus == 0)
			count += ft_printf_db(flags, len, number);
		else
			count += ft_putnbr(number) + ft_putflags(flags->width - len, ' ');
	}
	else if (flags->width > flags->point && flags->point >= len)
		count += ft_printf_dc(flags, len, number);
	return (count);
  */
  return len;
  
  /*

  int		num;
	int		strlen;
	char	*str;

	num = va_arg(finfo->ap, int);
	num = pf_check_negative_id(num, finfo);
	str = ft_itoa(num);
	strlen = (int)ft_strlen(str);
	if (finfo->precision > strlen)
		finfo->extra_zero = finfo->precision - strlen;
	pf_flag_checker_id(strlen, str, finfo);
	if (finfo->flag_minus == 1)
		print_minus_true(str, finfo);
	else
		printf_minus_false(str, finfo);
	free(str);
	finfo->format++;

  
  void	arg_print(t_format *arg, va_list *ap)
pf_di(arg, va_arg(*ap, int));
*/
}

    /* 
int ptf_str(t_fields *fields, va_list args_list){
  int len;
  int new_len;
  char *str;
  char  space;

  space = fields->fZero == 1 ? '0' : ' ';
  str = va_arg(args_list, char *);
  if (str == NULL){
    str = "(null)";
  }
		
  
  len = ft_strlen(str);
  new_len = (fields->precision >= 0 && fields->precision < len) ? fields->precision : len;
  
  if(fields->width > new_len){
    if(fields->fNegative != 1){
      pft_spaces(fields->width - new_len + 1, space);
      ft_putstr((const char *)ft_strsub(str, 0, new_len));
    } else{
      ft_putstr((const char *)ft_strsub(str, 0, new_len));
      pft_spaces(fields->width - new_len + 1, space);
    }
  } else 
    ft_putstr((const char *)ft_strsub(str, 0, new_len));

  return 1;
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
} */