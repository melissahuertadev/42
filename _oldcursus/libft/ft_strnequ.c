/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:06:18 by mhuerta           #+#    #+#             */
/*   Updated: 2019/08/30 06:54:14 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		i;
	int		r;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < (int)n)
	{
		if (s1[i] != s2[i])
		{
			r = 0;
			break ;
		}
		else
			r = 1;
		i++;
	}
	return (r);
}
