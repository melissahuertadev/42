/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:18:51 by mhuerta           #+#    #+#             */
/*   Updated: 2020/11/10 01:59:20 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_putcharcounter(char  c){
    
    ft_putchar(c);

    return 1;
}

char	*ft_utoa_hexa(unsigned int n, char spec)
{
    char    *s;
    int     tmp;
	size_t	l;
    char    conv;

	l = ft_uintlen(n, 16);
    conv = (spec == 'X') ? 'A' : 'a';
	if (!(s = ft_strnew(l)))
		return (NULL);
    if (n == 0)
        return "0";
	while (n)
	{
        l--;
        tmp = (n % 16);
        s[l] = tmp < 10 ? '0' + tmp : conv + tmp - 10;
        n = n / 16;
    }
    
	return (s);
}