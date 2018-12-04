/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wsize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 12:49:49 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/10 12:50:57 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wsize(const size_t size, char *buf, const size_t n)
{
	double	x;
	size_t	unit;

	x = (double)size;
	unit = 0;
	while ((x >= 1024.0) && (unit < 9))
	{
		x /= 1024.0;
		unit++;
	}
	return (ft_snprintf(buf, n, "%.2f%c", x, "bKMGTPEZY"[unit]));
}
