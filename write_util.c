#include "ft_printf.h"

int	ft_write(char *str, int c, char task_type)
{
	static int	w_count;
	int			i;

	i = 0;
	if (task_type == 'c')
	{
		write(1, &c, 1);
		w_count++;
	}
	else if (task_type == 'd')
		return (w_count);
	else
	{
	//Don't what this does, check later
		if (!str)
		{
			write(1, "(null)", 6);
			w_count += 6;
			return (w_count);
		}
	//Up to this point
		while (*(str + i))
		{
			write(1, &str[i], 1);
			w_count++;
			i++;
		}
	}
	if (task_type == 'i')
		free(str);
	return (w_count);
}
