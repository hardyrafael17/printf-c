/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpineiro <jpineiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:20:46 by jpineiro          #+#    #+#             */
/*   Updated: 2021/10/30 17:47:14 by jpineiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	size_t	i;

	i = n;
	if ((unsigned char *)str1 < (unsigned char *)str2)
		return (ft_memcpy(str1, str2, n));
	if (((!str1) && (!str2)) || n < 0)
		return (NULL);
	while (i--)
	{
		*(unsigned char *)(str1 + i) = *(unsigned char *)(str2 + i);
	}
	return (str1);
}
