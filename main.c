#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>


int	main(void)
{
	int original;
	int copy;

	original = printf("%d\n", INT_MAX);
	printf("%d\n\n", original);
	copy = ft_printf("%d\n", INT_MAX);
	printf("%d\n", copy);
	return (0);
}
