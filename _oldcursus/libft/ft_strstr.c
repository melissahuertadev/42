/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:12:29 by mhuerta           #+#    #+#             */
/*   Updated: 2020/10/07 19:57:49 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *h, const char *n)
{
	int		i;
	int		j;
	
	i = 0;
	if (h && n)
	{
		if (!*n)
			return ((char*)h);
		while (h[i])
		{
			j = 0;
			while (n[j] == h[i + j])
			{
				if (!(n[j + 1]))
					return ((char *)h + i);
				j++;
			}
			i++;
		}
	}
	return (NULL);
}
