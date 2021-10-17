/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 00:29:29 by mhuerta           #+#    #+#             */
/*   Updated: 2021/10/16 07:40:52 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    $> ./pipex file1 cmd1 cmd2 file2
    $> < file1 cmd1 | cmd2 > file2
*/

#include "../includes/pipex.h"

void    infile_process(int  pfd, char **av){
    //we are in the child process pfd[1], read
}

void    outfile_process(int  pfd, char **av){
    //we are in the parent process, pfd[0], write
}

int     main(int argc, char **argv)
{
    int     pfd[2];

    if (argc != 5 || pipe(pfd) < 0)
        return (1);
    if (fork() == 0) {
        infile_process(pfd[1], argv);
    } else
        outfile_process(pfd[0], argv);

	return (0);
}
