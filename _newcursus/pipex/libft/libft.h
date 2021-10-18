/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:58:37 by mhuerta           #+#    #+#             */
/*   Updated: 2021/10/18 08:06:48 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

char	*ft_strnstr(const char *h, const char *n, size_t len);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strcpy(char *d, char *s);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
int		ft_countwords(char *s, char delim);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);

#endif
