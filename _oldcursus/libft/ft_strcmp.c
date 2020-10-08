/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:13:16 by mhuerta           #+#    #+#             */
/*   Updated: 2020/10/07 19:56:56 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	*sttr1;
	unsigned char	*str2;
	
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1 && str2 && str1 == str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
