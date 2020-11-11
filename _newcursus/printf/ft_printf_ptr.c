/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 11:18:20 by mhuerta           #+#    #+#             */
/*   Updated: 2020/11/11 10:37:23 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ptf_ptr(t_fields *fields, va_list args)
{
	unsigned long int	n;
	char				*s;

	n = va_arg(args, unsigned long int);
	if (!n && fields->precision == 0)
		s = "";
	else
		s = ft_utoa_hexa_ln(n, 16);
	if (fields->width > 0 && fields->fminus)
	{
		fields->bytes += ft_printf("0x%s", s);
		fields->bytes += pft_spaces(fields->width - ft_strlen(s) - 1, ' ');
	}
	else if (fields->precision > fields->width)
		fields->bytes += ptf_ptr_aux(fields, s);
	else if (fields->width > 0)
	{
		fields->bytes += pft_spaces(fields->width - ft_strlen(s) - 1, ' ');
		fields->bytes += ft_printf("0x%s", s);
	}
	else
		fields->bytes += ft_printf("0x%s", s);
	return (fields->bytes);
}

char	*ft_utoa_hexa_ln(unsigned long int n, char spec)
{
	char	*s;
	int		tmp;
	size_t	l;
	char	conv;

	l = ft_uintlen_ln(n, 16);
	conv = (spec == 'X') ? 'A' : 'a';
	if (!(s = ft_strnew(l)))
		return (NULL);
	if (n == 0)
		return ("0");
	while (n)
	{
		l--;
		tmp = (n % 16);
		s[l] = tmp < 10 ? '0' + tmp : conv + tmp - 10;
		n = n / 16;
	}
	return (s);
}

int		ft_uintlen_ln(unsigned long n, unsigned int base)
{
	int		len;

	len = 1;
	while (n >= base)
	{
		n /= base;
		len++;
	}
	return (len);
}

int		ptf_ptr_aux(t_fields *fields, char *s)
{
	int		ret;

	ret = 0;
	ret += ft_printf("0x");
	ret += pft_spaces(fields->precision - fields->width, '0');
	ret += ft_printf("%s", s);
	return (ret);
}
