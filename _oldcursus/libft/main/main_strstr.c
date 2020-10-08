#include <string.h>
#include "libft.h"

int	main()
{
	const char s3[] = "Bye bye es adios!";
	const char s4[]	= "bye";
	const char s5[] = "byu";

	ft_putstr(strstr(s3, s4));
	ft_putstr(ft_strstr(s3, s4));

	return (0);
}
