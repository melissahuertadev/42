/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:59:55 by mhuerta           #+#    #+#             */
/*   Updated: 2021/10/18 00:50:48 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
