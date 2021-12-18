#include "ft_printf.h" 
#include <stdio.h>

int	main(void)
{
	int digit = 54;
	int count;
	char *null_str = NULL;
	int null_pointer_count;

	printf("\n");
	null_pointer_count = printf("O%p\n",(void *) 0);	
	printf("O%d\n", null_pointer_count);
	
	count =	ft_printf("C%p\n",  NULL,(void *)0);
	ft_printf("C%d\n", count);
	return (0);
}
