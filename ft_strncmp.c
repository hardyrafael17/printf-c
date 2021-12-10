/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpineiro <jpineiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:15:58 by jpineiro          #+#    #+#             */
/*   Updated: 2021/10/30 17:10:07 by jpineiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char	*s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < (n - 1) && *(unsigned char *)(s1 + i) != '\0' && \
	s2[i] != '\0' && s1[i] == s2[i])
		i++;
	if (n != 0)
		return ((*(unsigned char *)(s1 + i)) - (*(unsigned char *)(s2 + i)));
	else
		return (0);
}
