#include "libft.h"

int		main(void)
{
	char s1[] = "Hola";
	const char s3[] = " mundito. Chao";
	size_t n;

	n = 3;	
	ft_putstr(s1);
	ft_putchar('\n');
	ft_putstr(s3);
	ft_putchar('\n');
	ft_putstr(ft_strncat(s1, s3, n));

	// gcc -Wall -Wextra -Werror main_strncat.c ft_putstr.c ft_putchar.c ft_strncat.c
	
	return (0);
}
