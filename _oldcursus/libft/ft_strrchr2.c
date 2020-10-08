/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:12:14 by mhuerta           #+#    #+#             */
/*   Updated: 2020/10/07 19:57:37 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr2(const char *s, int c)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (s[i] == '\0')
		return ("\0");
	while (s[i++])
	{
		if (s[i] == (char)c)
			n = i;
	}
	while (s[n])
	{
		return ((char *)&s[n]);
		n++;
	}
	return ("\0");
}
