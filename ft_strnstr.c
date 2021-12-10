/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpineiro <jpineiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:20:03 by jpineiro          #+#    #+#             */
/*   Updated: 2021/10/30 17:09:19 by jpineiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (little[0] == 0)
		return ((char *) big);
	if (!ft_strncmp((char *) big, (char *) little, ft_strlen(little)))
		return ((char *)big);
	while (i < len - (ft_strlen(little) - 1) && \
	ft_strlen(little) <= ft_strlen(big) && len > 0)
	{
		if (!ft_strncmp((char *)(big + i), (char *)little, ft_strlen(little)))
		{
			return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
