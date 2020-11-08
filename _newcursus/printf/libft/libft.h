/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:58:37 by mhuerta           #+#    #+#             */
/*   Updated: 2020/11/07 18:21:03 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

size_t				ft_strlen(const char *s);
size_t          	ft_intlen(size_t n);
int					ft_isdigit(int c);
void				ft_putchar(char c);
void	            ft_putchar_fd(char c, int fd);
void	            ft_putnbr(int nb);
void	            ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void	            ft_putstr_fd(char const *s, int fd);
char				*ft_strsub(char const *s, unsigned int start, size_t len);


#endif
