/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:06:26 by mhuerta           #+#    #+#             */
/*   Updated: 2020/11/07 16:37:29 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ns;
	int		i;

	i = 0;
	if (!(ns = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	while (i < (int)len)
		ns[i++] = s[start++];
	ns[i] = '\0';
	return (ns);
}
