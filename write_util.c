#include "ft_printf.h"

int	ft_write(char *str, int c, char task_type)
{
	static int	w_count;
	int			i;

	i = 0;
	w_count = 0;
	if (task_type == "c")
	{
		write(1, &c, 1);
		w_count++;
	}
	else
	{
		while (*(str + i))
		{
			write(1, &(str + i), 1);
			w_count++;
		}
	}
	if (task_type == "e")
		free(str);
	return (w_count);
}
