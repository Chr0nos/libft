/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basetoul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 23:53:36 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/09 00:50:00 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_basetoul(const char *str, const char *map)
{
	const unsigned long		base = (unsigned long)ft_strlen(map);
	unsigned long			nb;
	unsigned int			p;
	int						x;

	if (!base)
		return (0);
	nb = 0;
	p = 0;
	while ((x = ft_strchrpos(map, str[p])) >= 0)
	{
		nb = nb * base + (unsigned long)x;
		p++;
	}
	return (nb);
}
