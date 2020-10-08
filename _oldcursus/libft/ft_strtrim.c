/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:06:44 by mhuerta           #+#    #+#             */
/*   Updated: 2020/10/07 19:46:30 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Allocates (with malloc(3)) and returns a copy of the string given as
**argument without whitespaces at the beginning or at the end
**of the string.
**Will be considered as whitespaces the following characters
**’ ’, ’\n’ and ’\t’.
**If s has no whitespaces at the beginning or at the end, the function
**returns a copy of s. If the allocation fails the function returns NULL.
**-> return value The “fresh” trimmed string or a copy of s.
*/

char	*ft_strtrim(char const *s)
{
	int		i;
	int		l;
	char	*ns;
	
	if (!s)
		return (NULL);
	i = 0;
	l = ft_strlen(s);
	while (ft_isspace(s[i])
		i++;
	if (i == l)
		return (ft_strnew(1));
	while (ft_isspace(s[l - 1])
		l--;
	ns = ft_strsub(s, i, (size_t)(l - s));
	return (ns);
}
