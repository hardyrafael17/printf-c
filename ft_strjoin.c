/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpineiro <jpineiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:30:30 by jpineiro          #+#    #+#             */
/*   Updated: 2021/11/06 19:41:16 by jpineiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *c1, char const *c2)
{
	int		i;
	int		j;
	char	*cadena;

	i = 0;
	j = 0;
	cadena = (char *)malloc(sizeof(char) * ft_strlen(c1) + ft_strlen(c2) + 1);
	if (cadena == NULL)
		return (NULL);
	while (c1[i] != '\0')
	{
		cadena[i] = *(char *)(c1 + i);
		i++;
	}
	while (c2[j] != '\0')
	{
		cadena[i] = *(char *)(c2 + j);
		i++;
		j++;
	}
	cadena[i] = '\0';
	return (cadena);
}
