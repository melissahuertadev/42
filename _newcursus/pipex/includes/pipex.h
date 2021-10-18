/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 00:25:28 by mhuerta           #+#    #+#             */
/*   Updated: 2021/10/18 06:57:41 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

char	*get_path(char *cmds, char **env);
void	check_cmd(char *argv, char **env);
void	infile_process(int pfd, char **av, char **env);
void	outfile_process(int pfd, char **av, char **env);

#endif
