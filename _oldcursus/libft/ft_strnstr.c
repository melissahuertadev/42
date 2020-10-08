/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:13:00 by mhuerta           #+#    #+#             */
/*   Updated: 2019/08/28 18:52:25 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	int		i;
	int		j;
	int		l;

	l = (int)len;
	i = 0;
	if (h && n)
	{
		if (!*n)
			return ((char*)h);
		while (h[i] && i < (l - 1))
		{
			j = 0;
			while (n[j] == h[i + j] && (i + j) < l)
			{
				if (!n[j + 1])
					return ((char *)h + i);
				j++;
			}
			i++;
		}
	}
	return (NULL);
}
