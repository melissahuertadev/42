/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 19:18:57 by mhuerta           #+#    #+#             */
/*   Updated: 2020/11/01 20:51:09 by mhuerta          ###   ########.fr       */
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
  
	| Case  | format        | args_list                   | output expected        |
	| --------------------- | --------------------------- | ---------------------- |
  | 0     | %s %s         | "hey my name is", "Melissa" | hey my name is Melissa | OK
  | 1     | %-2s-         | "hey Arnold"                | hey Arnold-            | OK
  | 2     | %-8s-         | "hey Arnold"                | hey Arnold  -          | OK
  
	| 0     | %c %-4cM      | '?', 42         | ? *   M                | OK
	| 2     | %-3c          | 'm'             | m  .                   | OK
	| 3     | %-11c         | 'm'             | m          .           | OK
	| 4     | %*c           | 5, 'm'          |     m.                 | OK
	| 5     | %-*c          | 5, 'm'          | m    .                 | OK
	| 6     | %03c.         | 'f'             | 00f.                   | OK



    printf("**** case 1: %%s %%-2s- values given: 'hey', 'Arnold' **\n");
    printf ("printf    ~ %s %-2s-\n", "hey", "Arnold");
    ft_printf ("printf    ~ %s %-2s-\n", "hey", "Arnold");
    printf("**** case 1: %%s %%-8s- values given: 'hey', 'Arnold' **\n");
    printf ("printf    ~ %s %-8s-\n", "hey", "Arnold");
    ft_printf ("printf    ~ %s %-8s-\n", "hey", "Arnold");
    
  ********************************************************************************
*/

//precision ~ less than the length, take the precision # 
//if width is > precision, fill width - precision, take part of the string to print (prec)

/*
  width:
    if the output string has fewer bytes than the field width it will be blank-padded
    on the left (or right, if the left-adjustment indicator has been given)
    to make up the field width (note that a leading zero is a flag, but an embedded 
    zero is part of a field width);
*/

/* int ptf_str(t_fields *fields, va_list args_list)
{
  int len;
  int ret;
  char *str;
  //char  space;

  ret = 0;
  //space = ' ';
  //len = ft_strlen(str);
  
  //printf("width %d\n", fields->width);
  
  str = va_arg(args_list, char *);
  if(str == NULL)
    str = "(null)";
  len = ft_strlen(str); */
  /*
  
  
void	pf_analyse_s(t_format *arg, char *str)
{
	int len;

	len = !str ? 6 : ft_strlen(str);
	if (arg->p >= 0 && arg->p < len)
		arg->n_str = arg->p;
	else
		arg->n_str = len;
	if (arg->w > arg->n_str)
	{
		arg->pad = (arg->zero && !arg->left) ? '0' : ' ';
		arg->n_pad = arg->w - arg->n_str;
	}
}
*/

  
  //si es *
  /* if (fields->wildcard == 1){
    fields->width = va_arg(args_list, int);
  }
 */
/*   printf("%d", fields->width);
  
  
  while(*str){
    ft_putchar(*str);
    str++;
    ret++;
  }
  
  
  //ret should count the # of chars
  ret++;
  return (ret); */


  /*
int	ft_printf_s(t_flags *flags, va_list args)
{
	int		count;
	char	*str;
	int		size;
	int		pad_size;

	ft_printf_star(flags, args);
	str = va_arg(args, char *);
	count = 0;
	if (flags->point == 0 && flags->width == 0)
		return (0);
	if (str == NULL)
		str = "(null)";
	size = (flags->point > ft_strlen(str) || flags->point == -1)
			? ft_strlen(str) : flags->point;
	pad_size = flags->width - size;
	if (!flags->minus)
		count += padding(pad_size, flags->zero ? '0' : ' ');
	while (size-- && *str)
		count += ft_putchar(*str++);
	if (flags->minus)
		count += padding(pad_size, ' ');
	return (count);
}
 * /
}
 } 
*/

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
}

//int pft_star(){

  /*
  void	ft_printf_star(t_flags *flags, va_list args)
{
	if (flags->star == 1)
		flags->width = va_arg(args, int);
	else if (flags->star == 2)
		flags->point = va_arg(args, int);
	else if (flags->star == 3)
	{
		flags->width = va_arg(args, int);
		flags->point = va_arg(args, int);
	}
	if (flags->width < 0)
	{
		flags->width = flags->width * -1;
		flags->minus = 1;
		flags->zero = 0;
	}
	if (flags->point < 0)
		flags->point = -1;
}

}*/