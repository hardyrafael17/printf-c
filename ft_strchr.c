/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpineiro <jpineiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:33:48 by jpineiro          #+#    #+#             */
/*   Updated: 2021/10/12 16:58:51 by jpineiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	cont;
	int		bool;

	bool = 0;
	cont = 0;
	while (s[cont] != '\0' && bool == 0)
	{
		if ((char)s[cont] == (char)c)
			bool = 1;
		else
			cont++;
	}
	if (c == '\0')
		return ((char *)s + cont);
	if ((!s) || bool == 0)
		return (NULL);
	return ((char *)s + cont);
}
