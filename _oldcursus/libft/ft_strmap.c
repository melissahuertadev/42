/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:05:42 by mhuerta           #+#    #+#             */
/*   Updated: 2019/10/16 20:24:24 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*nws;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen((char *)s);
	if (!(nws = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len--)
	{
		nws[i] = f((char)s[i]);
		i++;
	}
	nws[i] = '\0';
	return (nws);
}
