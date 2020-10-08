/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:06:26 by mhuerta           #+#    #+#             */
/*   Updated: 2019/09/02 16:52:07 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Allocates (with malloc(3)) and returns a “fresh” substring
**from the string given as argument.
**The substring begins at indexstart and is of size len.
**If start and len aren’t refering to a valid substring,
**the behavior is undefined.
**If the allocation fails, the function returns NULL.
**-> return value: the substring
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ns;
	int		i;

	i = 0;
	if (!(ns = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	while (i < (int)len)
		ns[i++] = s[start++];
	return (ns);
}
