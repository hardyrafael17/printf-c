/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpineiro <jpineiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:54:48 by jpineiro          #+#    #+#             */
/*   Updated: 2021/10/24 16:26:13 by jpineiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	char	guion;
	char	dos;
	char	res;

	guion = '-';
	dos = '2';
	if (nb < 0 && nb != -2147483648)
	{
		write(fd, &guion, 1);
		nb = nb * -1;
	}
	if (nb == -2147483648)
	{
		write(fd, &guion, 1);
		write(fd, &dos, 1);
		nb = (nb % -1000000000) * -1;
	}
	if ((nb / 10) > 0)
		ft_putnbr_fd(nb / 10, fd);
	res = nb % 10 + 48;
	write(fd, &res, 1);
}
