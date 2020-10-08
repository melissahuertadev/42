/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:59:55 by mhuerta           #+#    #+#             */
/*   Updated: 2019/09/02 16:42:22 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**https://www.youtube.com/watch?v=RtC496RWq84
*/

int	ft_countwords(char *s, char delim)
{
	int	isword;
	int	i;
	int	c;

	isword = 0;
	i = 0;
	c = 0;
	while (*(s + i))
	{
		if (*(s + i) == delim)
			isword = 0;
		else
		{
			if (isword == 0)
				c++;
			isword = 1;
		}
		i++;
	}
	return (c);
}
