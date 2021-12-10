/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpineiro <jpineiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:19:52 by jpineiro          #+#    #+#             */
/*   Updated: 2021/11/06 19:53:01 by jpineiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*cadena;

	i = 0;
	cadena = (char *)malloc((len + 1) * sizeof(char));
	if (start >= (unsigned int)ft_strlen(s))
	{
		cadena[i] = '\0';
		return (cadena);
	}
	if (cadena == NULL)
		return (NULL);
	while (i < len)
	{
		cadena[i] = s[start];
		i++;
		start++;
	}
	cadena[i] = '\0';
	return (cadena);
}
