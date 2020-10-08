/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:05:50 by mhuerta           #+#    #+#             */
/*   Updated: 2020/10/07 19:47:41 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*nws;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	if (!(nws = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len--)
	{
		nws[i] = f((unsigned int)i, (char)s[i]);
		i++;
	}
	nws[i] = '\0';
	return (nws);
}
