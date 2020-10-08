#include <string.h>
#include <stdio.h>
#include "libft.h"

int	main()
{
	char s1[7] = "Meli";//dst
	const char s2[] = "H. " ;//src
	size_t n;

	n = 10;
	ft_putnbr(sizeof(s1));
	ft_putchar('\n');
	ft_putnbr(sizeof(s2));
	ft_putchar('\n');
	// strlcat: initial length of dst + the length of src
		ft_putnbr(strlcat(s1, s2, n));
		ft_putchar('\n');
		ft_putnbr(ft_strlcat(s1, s2, n));
	ft_putchar('\n');

	return (0);
}
