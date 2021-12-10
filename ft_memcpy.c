/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpineiro <jpineiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:20:29 by jpineiro          #+#    #+#             */
/*   Updated: 2021/11/06 20:00:56 by jpineiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*c1;
	char	*c2;
	size_t	i;

	c1 = (char *)dst;
	c2 = (char *)src;
	i = 0;
	if ((!c1) && (!c2))
		return (NULL);
	while (i < n)
	{
		c1[i] = c2[i];
		i++;
	}
	return (c1);
}
