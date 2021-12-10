/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpineiro <jpineiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:39:44 by jpineiro          #+#    #+#             */
/*   Updated: 2021/11/04 19:49:00 by jpineiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **p, t_list *new)
{
	t_list	*lst;

	if (*p)
	{	
		lst = ft_lstlast(*p);
		lst->next = &*new;
	}
	else
		*p = new;
}
