/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:58:37 by mhuerta           #+#    #+#             */
/*   Updated: 2021/10/18 00:55:20 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

int	        ft_countwords(char *s, char delim);
char	    **ft_strsplit(char const *s, char c);
void	    ft_putchar_fd(char c, int fd);
void	    ft_putstr_fd(char const *s, int fd);

#endif
