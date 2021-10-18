/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 00:29:29 by mhuerta           #+#    #+#             */
/*   Updated: 2021/10/18 07:15:11 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    $> ./pipex file1 cmd1 cmd2 file2
    $> < file1 cmd1 | cmd2 > file2
*/

#include "../includes/pipex.h"

/*
	Execute any command sent
*/

char    *get_path(char *cmds, char **env)
{
    char	**folders;
	char	*path;
	char	*tmp;
    int		i;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	folders = ft_split(env[i] + 5, ':');
	i = 0;
	while (folders[i])
	{
		tmp = ft_strjoin(folders[i], "/");
		path = ft_strjoin(tmp, cmds);
		free(tmp);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	return (0);
}


void 	check_cmd(char *argv, char **env)
{
    char    **cmds;
    int     res;
	int		i;

	i = 0;
	if (*argv)
	{
		cmds = ft_split(argv, ' ');
        res = execve(get_path(cmds[0], env), cmds, env);
		if (res == -1)
        {
            perror("pipex: command not found");
            exit(1);
        }
	}

	exit(1);
}