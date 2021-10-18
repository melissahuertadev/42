/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 00:29:29 by mhuerta           #+#    #+#             */
/*   Updated: 2021/10/18 06:13:01 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    $> ./pipex file1 cmd1 cmd2 file2
    $> < file1 cmd1 | cmd2 > file2
*/

#include "../includes/pipex.h"

/*
	PARENT PROCESS:
	takes the pipe's end[0] as STDIN
	and the "outfitle" as STDOUT
*/
void	outfile_process(int end, char **av, char **env)
{
	int	fd;

	fd = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd >= 0)
	{
		dup2(end, STDIN_FILENO);
		close(end);
		dup2(fd, STDOUT_FILENO);
		close(fd);
		check_cmd(av[3], env);
	}
	else
	{
		close(end);
		perror(av[4]);
	}
}

/*
	CHILD PROCESS:
	takes the "infile" as STDIN
	and the pipe's end[1] as STDOUT
*/
void	infile_process(int end, char **av, char **env)
{		
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd >= 0)
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
		dup2(end, STDOUT_FILENO);
		close(end);
		check_cmd(av[2], env);
	}
	else
	{
		close(end);
		perror(av[1]);
	}
}

//end[0]: read, end[1]: write
int	main(int argc, char **argv, char **env)
{
	int	pipend[2];
	int	wstatus;

	if (argc != 5 || pipe(pipend) < 0)
	{
		ft_putstr_fd("pipex: bad arguments or pipe error\n", 2);
		return (1);
	}
	if (fork() == 0)
	{
		close(pipend[0]);
		infile_process(pipend[1], argv, env);
	}
	else
	{
		wait(&wstatus);
		close(pipend[1]);
		outfile_process(pipend[0], argv, env);
	}
	return (0);
}
