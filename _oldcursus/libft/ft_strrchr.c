/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:12:14 by mhuerta           #+#    #+#             */
/*   Updated: 2019/09/03 06:49:58 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen((char *)s);
	if ((char)c == '\0')
		return ((char *)s + len);
	while (len--)
		if(*(s + len) == c)
			return ((char *)s + len);
	return (NULL);
}
