/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:58:37 by mhuerta           #+#    #+#             */
/*   Updated: 2020/11/06 21:39:10 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

size_t				ft_strlen(const char *s);
int					ft_isdigit(int c);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);


#endif
