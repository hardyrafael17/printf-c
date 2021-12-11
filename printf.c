/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjimenez <hjimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 22:49:52 by hjimenez          #+#    #+#             */
/*   Updated: 2021/12/11 22:52:45 by hjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		d;
	char	c;
	char	*s;
	size_t	i;
	int		iv;

	i = 0;
	va_start(ap, fmt);
	while (fmt[i] != '%')
	{
		write(1, &fmt[i], 1);
		i++;
	}
	if (fmt[i] == '%')
	{
		i++;
		printf("Entra");
		if (fmt[i] == 's')
		{
			printf("Entra2");
			s = va_arg(ap, char *);
			printstr(s);
		}
		else if (fmt[i] == 'd')
		{
			d = va_arg(ap, int);
			s = ft_itoa(d);
			printstr(s);
		}
		else if (fmt[i] == 'c')
		{
			/* need a cast here since va_arg only
			   takes fully promoted types */
			c = (char) va_arg(ap, int);
			write(1,&c,1);
		}
		else if (fmt[i] == 'i')
		{
			iv = va_arg(ap, int);
			if (iv >= 0)
			{
				s = ft_itoa(d);
				printstr(s);
			}
			else
			{
		}
		}
	}
	va_end(ap);
	return (i);
}

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
	char	*cad;
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
	cad = (char *)ft_calloc(i + 2, sizeof(char));
	if (cad == NULL)
		return (NULL);
	if (o == -2147483648)
	{
		min_neg(o, cad);
		return (cad);
	}
	acaracteres(o, i, n, cad);
	return (cad);
}
void printstr(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
	{
		write(1,&str[i],1);
	}
}

int  main(){
  //  ft_printf("Hola que tal %d",8);
  printf("El número es %i", -2);
	printf("\nEl número es %d", -2);
		printf("\nEl número es %u", 2);
 
}