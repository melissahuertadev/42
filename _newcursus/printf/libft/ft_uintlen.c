/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 03:13:20 by mhuerta           #+#    #+#             */
/*   Updated: 2020/11/10 01:59:27 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_uintlen(unsigned int n, unsigned int	base)
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
