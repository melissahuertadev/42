/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:09:20 by mhuerta           #+#    #+#             */
/*   Updated: 2020/10/07 19:56:32 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp;
	char	*s;
	char	*d;
	int		i;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (dst == src || len == 0)
		return (dst);
	tmp = (char *)malloc(len);
	if (!tmp)
		return (NULL);
	else
	{
		ft_memcpy(tmp, src, len);
		ft_memcpy(d, tmp, len);
	}
	return (dst);
}
