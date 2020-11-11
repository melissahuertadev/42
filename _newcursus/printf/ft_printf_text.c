/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 19:18:57 by mhuerta           #+#    #+#             */
/*   Updated: 2020/11/11 10:36:28 by mhuerta          ###   ########.fr       */
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
  | 1     | %9s           | "Melissa"                   | `  Melissa`            | OK
  | 2     | %9s %3s       | "Melissa", "H"              | `  Melissa   H`        | OK
  | 3     | %-8s          | "Meli"                      | `Meli    `             | OK
  | 4     | %-0s          | "Meli"                      | `Meli`                 | OK
  | 5     | %*s           | 6, "Meli"                   | `  Meli`               | OK
  | 6     | %5.3s         | "banana"                    | `  ban`                | OK
  | 7     | %.3s          | "hello"                     | `hel`                  | OK
  | 8     | %10.s         | NULL                        | `          `           | OK
  | 9     | %.*s          | -3, NULL                    | `(null`                | OK
  | 10    | %s            | "testing testing"           | `testing testing`      | OK
  ********************************************************************************
*/
    
int		ptf_str(t_fields *fields, char *str)
{
	int		len;
	char	space;

	fields->bytes = 0;
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (fields->precision >= 0 && fields->precision < len)
		len = fields->precision;
	space = fields->fzero == 1 ? '0' : ' ';
	if (fields->width > len)
	{
		if (len == 0)
			fields->bytes += pft_spaces(fields->width + 1, space);
		else
			fields->bytes += ptf_str_left(fields, str, len);
	}
	else if (fields->width < 0)
		fields->bytes += ptf_str_left(fields, str, len);
	else
		ft_putstr((const char *)ft_strsub(str, 0, len));
	fields->bytes += len;
	return (fields->bytes);
}

int		ptf_str_left(t_fields *fields, char *str, int new_len)
{
	char	space;
	int		ret;

	if (fields->width < 0)
	{
		fields->fminus = 1;
		fields->width *= -1;
	}
	ret = 0;
	space = fields->fzero == 1 ? '0' : ' ';
	if (fields->fminus != 1)
	{
		ret += pft_spaces(fields->width - new_len + 1, space);
		ft_putstr((const char *)ft_strsub(str, 0, new_len));
	}
	else
	{
		ft_putstr((const char *)ft_strsub(str, 0, new_len));
		ret += pft_spaces(fields->width - new_len + 1, space);
	}
	return (ret);
}

int		ptf_char(t_fields *fields, int c)
{
	char	space;

	fields->bytes = 0;
	space = ' ';
	space = fields->fzero == 1 ? '0' : ' ';
	if (fields->width < 0)
	{
		fields->fminus = 1;
		fields->width *= -1;
	}
	if (fields->fminus == 1)
	{
		ft_putchar(c);
		fields->bytes += pft_spaces(fields->width, space);
	}
	else
	{
		fields->bytes += pft_spaces(fields->width, space);
		ft_putchar(c);
	}
	fields->bytes++;
	return (fields->bytes);
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