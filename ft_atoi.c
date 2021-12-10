/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpineiro <jpineiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 09:55:14 by jpineiro          #+#    #+#             */
/*   Updated: 2021/11/06 19:59:20 by jpineiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cont_space(const char *str, int *var)
{
	int	i;
	int	cminus;

	cminus = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'\
	|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			cminus *= -1;
		i++;
	}
	var[0] = i;
	var[1] = cminus;
}

int	ft_atoi(const char *str)
{
	size_t		i;
	int			cminus;
	size_t		res;
	size_t		num;
	static int	var[2];

	num = 0;
	res = 0;
	cont_space(str, var);
	i = (size_t)var[0];
	cminus = var[1];
	while (ft_isdigit(str[i]))
	{
		num = str[i] - '0';
		res = res * 10 + num;
		i++;
	}
	if (res > 2147483647 && cminus == 1)
		return (-1);
	else if (res > 2147483648 && cminus == -1)
		return (0);
	return (((int)res * cminus));
}
