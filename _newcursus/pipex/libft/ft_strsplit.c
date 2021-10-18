/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:07:03 by mhuerta           #+#    #+#             */
/*   Updated: 2021/10/18 01:20:29 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wrdlen(char const *w, char d)
{
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (w[i] && w[i] == d)
		i++;
	while (w[i] && w[i] != d)
	{
		i++;
		l++;
	}
	return (l);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		cw;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	cw = ft_countwords((char *)s, c);
	if (!s || !(arr = (char **)malloc(sizeof(char *) * cw + 1)))
		return (NULL);
	while (i < cw)
	{
		k = 0;
		arr[i] = (char *)malloc(sizeof(char) * (ft_wrdlen(&s[j], c) + 1));
		if (!(arr[i]))
			return (NULL);
		while (s[j] == c)
			j++;
		while (s[j] && s[j] != c)
			arr[i][k++] = s[j++];
		arr[i][k] = '\0';
		i++;
	}
	arr[i] = 0;
	return (arr);
}