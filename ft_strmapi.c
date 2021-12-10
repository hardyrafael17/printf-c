/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpineiro <jpineiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:36:01 by jpineiro          #+#    #+#             */
/*   Updated: 2021/10/14 19:39:37 by jpineiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*cadena;
	size_t	i;

	i = 0;
	cadena = (char *)malloc(ft_strlen(s) + 1 * sizeof(char));
	if (cadena == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		cadena[i] = (*f)(i, s[i]);
		i++;
	}
	cadena[i] = '\0';
	return (cadena);
}
