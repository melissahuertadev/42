/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:07:13 by mhuerta           #+#    #+#             */
/*   Updated: 2020/10/07 19:55:28 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	size_t	i;
	size_t	l;

	i = 1;
	l = ft_strlen((size_t)n);
	if (!(s = ft_strnew(l)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(s, "-2147483648"));
	if (n < 0)
	{
		s[0] = '-';
		n = n * -1;
	}
	if (n == 0)
		s[0] = '0';
	while (n > 0)
	{
		s[l - i++] = (n % 10) + '0';
		n = n / 10;
	}
	return (s);
}
