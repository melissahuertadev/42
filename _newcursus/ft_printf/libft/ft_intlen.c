/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 03:13:20 by mhuerta           #+#    #+#             */
/*   Updated: 2019/10/16 18:57:20 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(size_t n)
{
	size_t	len;
	size_t	tmp;

	tmp = 1;
	len = 0;
	if (n == 0)
		return (1);
	if ((int)n < 0)
	{
		n *= -1;
		len++;
	}
	while (tmp <= n)
	{
		len++;
		tmp *= 10;
	}
	return (len);
}
