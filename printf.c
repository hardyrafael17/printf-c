/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjimenez <hjimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 22:49:52 by hjimenez          #+#    #+#             */
/*   Updated: 2021/12/12 12:20:13 by hjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

size_t			printstr(char *str);
static	void		min_neg(int o, char *cad);
static void		acaracteres(int o, int i, int n, char *cad);
char			*ft_itoa(int num);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);

void	ft_bzero(void *s, size_t n)
{
	char			*cadena;
	size_t			i;

	cadena = (char *) s;
	i = 0;
	while (i < n)
	{
		cadena[i] = '\0';
		i++;
	}	
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*puntero;

	puntero = (void *)malloc(size * count);
	if (puntero == NULL)
		return (NULL);
	ft_bzero(puntero, size * count);
	return (puntero);
}

size_t	printstr(char *str)
{
	int	i;
	size_t printedChars;

	printedChars = 0;
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
		printedChars++;
	}
	return (printedChars);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		d;
	char	c;
	char	*s;
	size_t	i;
	int		iv;
	size_t	printedChars;

	printedChars = 0;
	i = 0;
	va_start(ap, fmt);
	while (fmt[i] != 0 && fmt[i] !='%')
	{
		write(1, &(fmt[i]), 1);
		i++;
		printedChars++;
	}
	
	if (fmt[i] == '%')
	{
		i++;
		if (fmt[i] == 's')
		{
			printf("Entra2");
			s = va_arg(ap, char *);
			return 1;
			printstr(s);
		}
		
		else if (fmt[i] == 'd')
		{
			return 1;
			d = va_arg(ap, int);
			s = ft_itoa(d);
			printstr(s);
		}
		else if (fmt[i] == 'c')
		{
			/* need a cast here since va_arg only
			   takes fully promoted types */
			   
			   return 1;
			c = (char) va_arg(ap, int);
			write(1, &c, 1);
		}
		else if (fmt[i] == 'i')
		{
				s = ft_itoa(va_arg(ap, int));
				printedChars += printstr(s);
		}
	}
	va_end(ap);
	return (printedChars);
}
static size_t	ft_convert_number(int n)
{
	size_t	nn;

	if (n < 0)
	{
		nn = (n + 1) * -1;
		nn++;
	}
	else
		nn = n;
	return (nn);
}

static int	get_arr_size(int n)
{
	signed int	sign;
	size_t		stn;
	size_t		arr_length;

	arr_length = 1;
	if (n == 0)
		return (2);
	else if (n == -2147483648)
		return (12);
	if (n < 0)
	{
		sign = -1;
		stn = (n * sign);
		arr_length++;
	}
	else
		stn = n;
	while (stn != 0)
	{
		stn = (stn / 10);
		arr_length++;
	}
	return (arr_length);
}

char	*ft_itoa(int n)
{
	size_t	nn;
	int		arrlength;
	char	*character;
	size_t	index;

	arrlength = get_arr_size(n);
	character = ft_calloc(arrlength--, sizeof(char));
	if (!character)
		return (NULL);
	if (n < 0)
		character[0] = '-';
	nn = ft_convert_number(n);
	if (n == 0)
		character[0] = '0';
	index = 0;
	while (nn != 0)
	{
		*(character + arrlength - 1 - index) = '0' + nn % 10;
		nn = (nn / 10);
		index++;
	}
	return (character);
}

int	main(void)
{
  //  ft_printf("Hola que tal %d",8);
	int	printed_chars;

	
	printed_chars = ft_printf("El número es %i", 5555);
	ft_printf("\nPrinted charachters are ***%i", printed_chars);
}


/*Project Flow
##Modulo 1, iterate
1- Recieve arguments
2- Iterate over characters while not nulll
	1- if char is not "%", then add it to the print_string, then call (1-2 iterator).
	2- if char is "%", then then call (2-1 flag check)


##Modulo 2, check for flags
1-validate flags

##Modulo 3, check for format specifiers
1-check format to be printed
2-Call formatter for each format
3-Append to pritn string (with format specifiers included
*/
