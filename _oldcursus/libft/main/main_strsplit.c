/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:25:00 by mhuerta           #+#    #+#             */
/*   Updated: 2019/09/02 11:39:02 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main()
{
	char	*s1 = "*hello*fellow***students*";
	char	c1 = '*';
	char    *s2 = "88Como888888estas88?8Bien?*";
	char    c2 = '8';

	printf("count of words: %i\n", ft_countwords(s1, c1));
	printf("count of words: %i\n", ft_countwords(s2, c2));
	return (0);
}
