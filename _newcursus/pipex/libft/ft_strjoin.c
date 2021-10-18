/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:06:36 by mhuerta           #+#    #+#             */
/*   Updated: 2021/10/18 14:13:33 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Allocates (with malloc(3)) and returns a “fresh” string
**ending with ’\0’, result of the concatenation of s1 and s2.
**If the allocation fails the function returns NULL.
**Param 1: prefix string | Param 2: suffix string.
**
**-> return value: “fresh” string result of the concatenation.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ns;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((s1) + ft_strlen(s2) + 1);
	ns = (char *)malloc(sizeof(char) * len);
	if (!ns)
		return (NULL);
	ft_strcpy(ns, (char *)s1);
	ft_strcat(ns, s2);
	return (ns);
}
