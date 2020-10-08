/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:40:44 by mhuerta           #+#    #+#             */
/*   Updated: 2019/10/18 02:36:50 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This program prints the value saved on the buffer x]
*You have to create a file named "t1" in order to this to work
*RUN THIS: gcc get_next_buffer.c libft/ft*.c
*Thanks!
*/

#include "get_next_line.h"

int		main()
{
	int	fd;
	int	ret;
	char buf[BUFF_SIZE + 1];

	fd = open("t1", O_RDONLY);
	//fd = open("t0", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		ft_putstr("open() failed\n");
		return (1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		ft_putstr(buf);
		ft_putnbr(ret);
		ft_putchar('*');
	}
	ft_putchar('\n');
	//ft_putchar_fd('Z', fd);
	//ft_putstr_fd("hey", fd);
	if (close(fd) == -1)
	{
		ft_putstr("close() failed\n");
		return (1);
	}
	return (0);
}
