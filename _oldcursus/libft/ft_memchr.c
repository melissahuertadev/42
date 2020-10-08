/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:09:28 by mhuerta           #+#    #+#             */
/*   Updated: 2019/08/26 21:29:03 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*src;
	int		i;
	int		j;
	char	*result;

	src = (char *)s;
	result = src;
	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] == (unsigned char)c)
			break ;
		i++;
	}
	while (n--)
		result[j++] = src[i++];
	return (src);
}
