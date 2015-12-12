/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:44:32 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/12 21:24:40 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_rec(unsigned int nb, char *buffer)
{
	if (nb == 0)
		ft_strncpy(buffer, "0", 2);
	else
	{
		*buffer = nb % 10 + '0';
		nb /= 10;
		if (nb)
			ft_putnbr_rec(nb, buffer + 1);
		else
			*(++buffer) = '\0';
	}
}

void		ft_putnbr(int n)
{
	char	buffer[12];

	if (n < 0)
	{
		*buffer = '-';
		ft_putnbr_rec((unsigned int)-n, (char*)buffer + 1);
	}
	else
		ft_putnbr_rec((unsigned int)n, (char*)buffer);
	ft_strrev(buffer + ((n < 0) ? 1 : 0));
	ft_putstr(buffer);
}
