/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 11:18:20 by mhuerta           #+#    #+#             */
/*   Updated: 2020/11/11 10:41:02 by mhuerta          ###   ########.fr       */
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

int		ptf_dcm(t_fields *fields, int dec)
{
	int	len;
	int	sign;

	len = ft_intlen(dec);
	sign = (dec < 0) ? 1 : 0;
	if (dec < 0)
		len--;
	if (fields->width < 0)
	{
		fields->fminus = 1;
		fields->width *= -1;
	}
	if (dec == 0 && fields->precision == 0)
		return (pft_spaces(fields->width + 1, ' '));
	if (fields->width == 0 || fields->precision > fields->width)
		fields->width = fields->precision;
	if (fields->width >= len)
		ptf_dcm_setpad(fields, len, sign);
	ptf_dcm_printing(fields, dec);
	return (fields->bytes);
}

void	ptf_dcm_setpad(t_fields *fields, int len, int sign)
{
	if (fields->precision > len)
	{
		fields->qzeros = fields->precision - len;
		len += fields->qzeros;
		fields->qspaces = fields->width - len - sign;
	}
	else if (fields->fzero && fields->fminus != 1 && fields->precision < 0)
		fields->qzeros = fields->width - len - sign;
	else
		fields->qspaces = fields->width - len - sign;
}

void	ptf_dcm_printing(t_fields *fields, int dec)
{
	if (fields->fminus == 0)
		fields->bytes += pft_spaces(fields->qspaces + 1, ' ');
	if (dec < 0 && dec != -2147483648)
	{
		dec *= -1;
		ft_putchar('-');
		fields->bytes++;
	}
	fields->bytes += pft_spaces(fields->qzeros + 1, '0');
	ft_putnbr(dec);
	fields->bytes += ft_intlen(dec);
	if (fields->fminus == 1)
	{
		fields->bytes += pft_spaces(fields->qspaces + 1, ' ');
	}
}