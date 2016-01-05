/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 12:43:17 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/05 12:50:23 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putull_r(unsigned long long n, char *buffer)
{
	if (n > 16)
		ft_putull_r(n / 16, buffer + 1);
	buffer[0] = "0123456789ABCDEF"[n % 16];
	buffer[1] = '\0';
}

void		ft_putull(unsigned long long n)
{
	char	buffer[19];

	ft_putull_r(n, (char *)buffer);
	ft_putstr(buffer);
}
