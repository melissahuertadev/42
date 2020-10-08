#include "libft.h"
#include <string.h>

int		main(void)
{
	char s1[] = "Hola";
	const char s2[] = "Mundo";
	size_t n;

	n = 3;	
	ft_putstr(s1);
	ft_putchar('\n');
	ft_putstr(s2);
	ft_putchar('\n');
	ft_putnbr(ft_strncmp(s1, s2, n));
	ft_putchar('\n');
	ft_putnbr(strncmp(s1, s2, n));
	ft_putchar('\n');

	//gcc -Wall -Wextra -Werror main_strncmp.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_strncmp.c 


	return (0);
}
