/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:40:44 by mhuerta           #+#    #+#             */
/*   Updated: 2020/10/08 16:23:34 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/****		PLEASE, START WITH THE MAIN.. SCROLL DOWN DOWN             ****/

/*
**READ EVERY FREAKING LINE
**So we recieve the superbuffer as an input, remember that the superbuffer has
**all the content of the file. And also the variable "line" from the main,
**this variable is the one that is going to be "affected by all the changes"
**(sorry, if my lack of english words doesnt let me express as i wanted to)
**Then we are going to look for the breaklines and the EOF, so we can 
**"affect" every line, i would say retur but actually we are not returning
**anything, we are not printing anything either.. Thats what make this project
**a little difficult to understand at the beginning, we usually expect something
**tangible, or visible, thats why i recommend always PRINT your output.
***********************************THE END***********************************
************
**Return 1 when read the line has been read
**Return 0 when the reading has been completed
**Return -1 in case of error
*/

int		ft_read_frkg_line(char **sb, int fd, char **l, int ret)
{
	char	*t;
	int		num;

	num = 0;
	while(sb[0][num] == '\n' && sb[0][num] == '\0')
		num++;
	if (sb[0][num] == '\n')
	{
		*l = ft_strsub(sb[0], 0, num);
		t = ft_strdup(sb[0] + num + 1);
		ft_strdel(&sb[0]);
		sb[0] = t;
		if (sb[0][0] == '\0')
			ft_strdel(&sb[0]);
	}
	else if (sb[0][num] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, l));
		*l = ft_strdup(sb[0]);
		ft_strdel(&sb[0]);
	}
	return (1);
}

/*
**GET_NEXT_LINE()
**1. Start reading information using the fd & allocate memory for string variables
**buff: temporary area that stores data;
**ret: # of characters read and stored in the buff;
**superbuff = buff^1 + buff^2 + buff^3.... until EOF;
**-> tmp = superbuff + buff^x;
**-> superbuff = tmp;
**2. Validates variables: fd, line & ret -> this could be validated at the beginning 
**or at the end, but this are validated at reading the file, starting the while loop,
**so we are GOOD!
**3. Value on fd variable is sent to "READ EVERY FREAKING LINE" or to every other function
**you want to create :), so each one (func) can recognize with file is reading.
******************
**OPTIONAL, YOU CAN ADD THIS , BUT FOR THIS PROJECT "WRITE" IS A FORBIDDEN FUNCTION
**if (fd < 0)
***ft_putstr("open() failed\n");
**if (ret < 0)
***ft_putstr("error while reading the file\n");
*/

int		get_next_line(const	int fd, char **line)
{
	char	buff[BUFF_SIZE];
	char	ret;
	static char	*superbuff[255];
	char	*tmpstr;

	while (((ret = read(fd, buff, BUFF_SIZE)) > 0) && fd >= 0)
	{
		buff[ret] = '\0';
		if (superbuff[0] == NULL)
			superbuff[0] = ft_strnew(1);
		tmpstr = ft_strjoin(superbuff[0], buff);
		ft_strdel(&superbuff[0]);
		superbuff[0] = tmpstr;
		//ft_putstr(superbuff[0]);
		//ft_putnbr(fd); -> is always 3, or at least it always starts with 3 :O
		if (ft_strchr(superbuff[0], '\n'))
			break ;
	}
	if (fd < 0 || line == NULL || ret < 0)
		return (-1);
	else if (ret == 0 && (superbuff[0] == NULL || superbuff[0][0] == '\0'))
		return (0);
	return (ft_read_frkg_line(superbuff, fd, line, ret));
}

/*
**MAIN()
**i: counter of argv ; r: return value of get_next_line
**This only accepts the first parameter as an input file and send the fd to the
**get_next_line function, otherwise do nothing.
*/

int		main(int ac, char **av)
{
	int		fd;
	char	*s;
	int		i;
	int		r;

	i = 1;
	while (ac > i)
	{
		fd = open(av[i], O_RDONLY);
		while ((r = get_next_line(fd, &s)) > 0)
		{
			//printf("Line: %s\n", s);
			free(s);
		}
		close(fd);
		i++;
	}
	return (0);
}
