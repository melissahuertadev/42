/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 00:25:28 by mhuerta           #+#    #+#             */
/*   Updated: 2021/10/18 01:29:11 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include <unistd.h>
 #include <stdio.h>
# include <fcntl.h>

void 	check_cmd(char *argv); //, char** env);
void	infile_process(int pfd, char **av); //, char **env);
void	outfile_process(int pfd, char **av); //, char **env);
int		main(int argc, char **argv); //, char **env);

#endif
