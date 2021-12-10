/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpineiro <jpineiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:33:48 by jpineiro          #+#    #+#             */
/*   Updated: 2021/10/12 16:59:41 by jpineiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	cont;

	cont = 0;
	while (s[cont] != '\0')
		cont++;
	while (cont >= 0)
	{
		if ((unsigned char)s[cont] == (unsigned char)c)
			return ((char *)(s + cont));
		cont--;
	}
	return (NULL);
}
