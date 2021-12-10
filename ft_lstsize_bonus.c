/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpineiro <jpineiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:17:25 by jpineiro          #+#    #+#             */
/*   Updated: 2021/11/04 19:43:47 by jpineiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	pos;

	pos = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		pos++;
	}
	return (pos);
}
