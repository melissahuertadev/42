/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:11:30 by mhuerta           #+#    #+#             */
/*   Updated: 2020/10/07 19:47:50 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*s;
	size_t	i;

	s = dest;
	i = 0;
	if ((*dest != '\0') && (*src != '\0'))
	{
		while (*dest != '\0')
			dest++;
		while (i < n)
		{
			i++;
			*dest++ = *src++;
		}
		*dest = '\0';
	}
	return (s);
}
