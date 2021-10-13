/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 00:29:29 by mhuerta           #+#    #+#             */
/*   Updated: 2021/10/13 02:35:42 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Your objective is to code the Pipex program. It should be executed in this way:
    $> ./pipex file1 cmd1 cmd2 file2
Just in case: file1 and file2 are file names, cmd1 and cmd2 are shell commands with their parameters.
The execution of the pipex program should do the same as the next shell command:
    $> < file1 cmd1 | cmd2 > file2
III.1 Examples
     $> ./pipex infile ``ls -l'' ``wc -l'' outfile
should be the same as “< infile ls -l | wc -l > outfile”
     $> ./pipex infile ``grep a1'' ``wc -w'' outfile
should be the same as “< infile grep a1 | wc -w > outfile”


like the shell command < file1 cmd1 | cmd2 > file2.


*/

#include "../includes/pipex.h"


int	main(int argc, char **argv)
{
	if (argc != 5)
		return (-1);
        
	return (0);
}