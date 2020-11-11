/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 11:04:13 by mhuerta           #+#    #+#             */
/*   Updated: 2020/11/11 10:34:48 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ptf_uns_dcm(t_fields *fields, unsigned int dec)
{
  int		len;

	len = ft_uintlen(dec, 10);
	if (fields->width < 0)
	{
		fields->fminus = 1;
		fields->width *= -1;
	}
	if (dec == 0 && fields->precision == 0)
		return (pft_spaces(fields->width + 1, ' '));
	else
		pft_setpadding(fields, len);
	pft_unsigned_int(fields, dec);
	fields->bytes += len;
	return (fields->bytes);
}


int ptf_uns_hexa(t_fields *fields,  unsigned int dec)
{
  char	*hexadec;
	int		len;

	hexadec = ft_utoa_hexa(dec, fields->spec);
	len = ft_strlen(hexadec);
	if (fields->width < 0)
	{
		fields->fminus = 1;
		fields->width *= -1;
	}
	if (dec == 0 && fields->precision == 0)
	{
		fields->bytes += pft_spaces(fields->width + 1, ' ');
		return (fields->width);
	}
	else
		pft_setpadding(fields, len);
	pft_unsigned_char(fields, hexadec);
	fields->bytes += len;
	return (fields->bytes);
}

void pft_setpadding(t_fields *fields, int len)
{
  fields->qspaces = -1;
	fields->qzeros = -1;
	if (fields->width > 0 && fields->precision > 0)
	{
		fields->qzeros = fields->precision - len;
		fields->qspaces = fields->width - len;
		if (fields->qzeros > 0)
			fields->qspaces -= fields->qzeros;
	}
	else if (fields->width > 0)
	{
		if (fields->fzero && fields->precision < 0)
			fields->qzeros = fields->width - len;
		else
			fields->qspaces = fields->width - len;
	}
	else if (fields->precision > 0)
		fields->qzeros = fields->precision - len;
}

void	pft_unsigned_char(t_fields *fields, char *s)
{
	if (fields->fminus == 0)
		fields->bytes += pft_spaces(fields->qspaces + 1, ' ');
	fields->bytes += pft_spaces(fields->qzeros + 1, '0');
	ft_putstr(s);
	if (fields->fminus == 1)
		fields->bytes += pft_spaces(fields->qspaces + 1, ' ');
}

void	pft_unsigned_int(t_fields *fields, unsigned int nbr)
{
	if (fields->fminus == 0)
		fields->bytes += pft_spaces(fields->qspaces + 1, ' ');
	fields->bytes += pft_spaces(fields->qzeros + 1, '0');
	ft_putunbr(nbr);
	if (fields->fminus == 1)
		fields->bytes += pft_spaces(fields->qspaces + 1, ' ');
}
