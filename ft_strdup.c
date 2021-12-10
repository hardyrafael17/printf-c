/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpineiro <jpineiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:09:27 by jpineiro          #+#    #+#             */
/*   Updated: 2021/10/03 13:38:11 by jpineiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*p1;
	char	*p;

	i = 0;
	p1 = (char *) s1;
	p = (char *)malloc((sizeof(*p1) * (ft_strlen(p1) + 1)));
	if (p == NULL)
	{
		return (NULL);
	}
	while (p1[i] != '\0')
	{
		p[i] = p1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
