/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjimenez <hjimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 22:49:52 by hjimenez          #+#    #+#             */
/*   Updated: 2021/12/15 21:28:44 by hjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	va_arg;
	size_t	i;

	i = 0;
	va_start(va_arg, fmt);
	while (*(fmt + i))
	{
		if (*(fmt + i) == '%')
		{
			ft_formatter(va_arg, fmt[i + 1]);
			i += 2;
		}
		else
		{
			ft_write(NULL, fmt[i], 'c');
			i++;
		}
	}
	va_end(va_arg);
	return (ft_write(NULL, 'n', 'd'));
}
