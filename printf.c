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
#include "utils.c"

int	ft_printf(const char *fmt, ...)
{
	va_list	va_arg;
	size_t	i;
	size_t	word_count;

	i = 0;
	word_count = 0;
	va_start(va_arg, fmt);
	while (*(fmt + i))
	{
		if (*(fmt + i) == '%')
		{
			word_count = ft_formatter(va_arg, *(fmt + i + 1), word_count);
			i += 2;
		}
		else
		{
			write(1, (fmt + i), 1);
			i++;
			word_count++;
		}
	}
	va_end(va_arg);
	return (word_count);
}

int	main(void)
{
	int	printed_chars;
	int	original_printed_chars;

	original_printed_chars = printf("Hello world, original >>%d\n", 5555);
	printf("Printed chars are %d\n\n", original_printed_chars);
	printed_chars = ft_printf("Hello world, original >>%d\n", 5555);
	ft_printf("Printed chars are %d\n\n", printed_chars);
	return (0);
}
