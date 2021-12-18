/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjimenez <hjimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:24:04 by hjimenez          #+#    #+#             */
/*   Updated: 2021/12/15 21:49:56 by hjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	min_neg(int o, char *cad)
{
	char	*num2;
	int		x;

	x = 0;
	num2 = "-2147483648";
	if (o == -2147483648)
	{
		while (num2[x] != '\0')
		{
			cad[x] = num2[x];
			x++;
		}
	}
}

static void	acaracteres(int o, int i, int n, char *cad)
{
	int	num;

	num = i;
	if (n < 0)
		n = n * -1;
	while (i >= 0)
	{
		cad[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	n = 0;
	cad[num + 1] = '\0';
	while (n <= num && o > 0)
	{
		cad[n] = cad[n + 1];
		n++;
	}
	if (o < 0)
		cad[0] = '-';
}

char	*ft_itoa(int num)
{
	int		i;
	char	*str;
	int		n;
	int		o;

	o = num;
	n = num;
	i = 0;
	if (num < 0)
		num = num * -1;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	str = (char *)malloc(i + 2);
	if (str == NULL)
		return (NULL);
	if (o == -2147483648)
	{
		min_neg(o, str);
		return (str);
	}
	acaracteres(o, i, n, str);
	return (str);
}

int	ft_printstring(char *str, int size)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (size + 6);
	}
	while (str[i])
	{
		write(1, &str[i++], 1);
		size++;
	}
	return (size);
}

char	*ft_itoa_void(unsigned long int n, char *base)
{
	int					size;
	char				*a;
	unsigned long int	num;

	if (n == 0)
		return (NULL);
	size = 0;
	num = n;
	if (num == 0)
		size++;
	while (num != 0)
	{
		num = num / 16;
		size++;
	}
	a = malloc(size + 1);
	a[size] = '\0';
	size--;
	while (n >= 16 && 0 < size)
	{
		a[size] = base[n % 16];
		n = n / 16;
		size--;
	}
	a[size--] = base[n % 16];
	return (a);
}

size_t	printstr(char *str)
{
	int		i;
	size_t	printed_chars;

	printed_chars = 0;
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
		printed_chars++;
	}
	return (printed_chars);
}

int	ft_printchar(char c, int w_count)
{
	write(1, &c, 1);
	w_count++;
	return (w_count);
}

void	ft_printvoid(void *ptr)
{
	char		*strnum;

	strnum = ft_itoa_void((unsigned long int) ptr, "0123456789abcdefg");
	if (!strnum)
		ft_write("(nil)", 'n', 'e');
	else
	{	
		ft_write("0x", 'n', 'e');
		ft_write(strnum, 'n', 'i');
	}
}

int	ft_lp(char *str, int size)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i++], 1);
		size++;
	}
	free(str);
	return (size);
}

char	*ft_itoa_unsig(unsigned int n)
{
	char			*a;
	int				size;
	unsigned int	num;

	size = 0;
	num = n;
	if (num == 0)
		size++;
	while (num != 0)
	{
		num = num / 10;
		size++;
	}
	a = (char *)malloc((size + 1) * sizeof(char));
	if (!a)
		return (0);
	a[size--] = '\0';
	while (n >= 10)
	{
		a[size] = n % 10 + '0';
		n = n / 10;
		size--;
	}
	a[size--] = n + '0';
	return (a);
}

char	*ft_ib(unsigned int n, char *base)
{
	int				size;
	char			*a;
	unsigned int	num;

	size = 0;
	num = n;
	if (num == 0)
		size++;
	while (num != 0)
	{
		num = num / 16;
		size++;
	}
	a = malloc(size + 1);
	a[size] = '\0';
	size--;
	while (n >= 16 && 0 < size)
	{
		a[size] = base[n % 16];
		n = n / 16;
		size--;
	}
	a[size--] = base[n % 16];
	return (a);
}

void ft_formatter(va_list args, char c)
{
	if (c == 'c')
		ft_write(NULL, va_arg(args, int), 'c');
	if (c == 's')
		ft_write(va_arg(args, char *),'n', 'e');
	if (c == 'p')
		ft_printvoid(va_arg(args, void *));
	if (c == 'd' || c == 'i')
		ft_write(ft_itoa(va_arg(args, int)), 'n', 'i');
	if (c == 'u')
		ft_write(ft_itoa_unsig(va_arg(args, unsigned int)), 'n', 'i');
	if (c == 'x')
		ft_write(ft_ib(va_arg(args, int), "0123456789abcdef"), 'n', 'i');
	if (c == 'X')
		ft_write(ft_ib(va_arg(args, int), "0123456789ABCDEF"), 'n', 'i');
	if (c == '%')
		ft_write(NULL, '%', 'c');
}
