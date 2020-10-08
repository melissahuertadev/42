/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:11:39 by mhuerta           #+#    #+#             */
/*   Updated: 2020/10/07 19:47:35 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	d;

	i = 0;
	d = size - ft_strlen(dest);
	if ((*dest != '\0') && (*src != '\0'))
	{
		while (*dest != '\0')
			dest++;
		while (*src != '\0' && i < d)
		{
			i++;
			*dest++ = *src++;
		}
		*dest = '\0';
	}
	return (i);
}
