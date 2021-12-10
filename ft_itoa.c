/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpineiro <jpineiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:07:02 by jpineiro          #+#    #+#             */
/*   Updated: 2021/11/06 20:00:17 by jpineiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
