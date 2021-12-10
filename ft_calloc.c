/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpineiro <jpineiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:48:56 by jpineiro          #+#    #+#             */
/*   Updated: 2021/10/05 18:18:15 by jpineiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*puntero;

	puntero = (void *)malloc(size * count);
	if (puntero == NULL)
		return (NULL);
	ft_bzero(puntero, size * count);
	return (puntero);
}
