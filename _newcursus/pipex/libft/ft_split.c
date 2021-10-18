/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:07:03 by mhuerta           #+#    #+#             */
/*   Updated: 2021/10/18 14:21:09 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_word(char **arr, int *n)
{
	while (*n >= 0)
		free(arr[*n--]);
	free(arr);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ns;
	int		i;

	i = 0;
	ns = (char *)malloc(sizeof(char) * len);
	if (!ns)
		return (NULL);
	while (i < (int)len)
		ns[i++] = s[start++];
	return (ns);
}

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

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		cw;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cw = ft_countwords((char *)s, c);
	arr = (char **)malloc(sizeof(char *) * cw + 1);
	if (!s || !arr)
		return (NULL);
	while (s[j])
	{
		if (s[j] != c && (j == 0 || s[j - 1] == c))
		{
			arr[i] = ft_strsub(s + j, 0, ft_wrdlen(s + j, c));
			if (!arr[i])
				free_word(arr, &i);
			i++;
		}
		j++;
	}
	arr[i] = 0;
	return (arr);
}
