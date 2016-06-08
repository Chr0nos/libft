/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basetoul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 23:53:36 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/09 00:28:13 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_basetoul(const char *str, const char *map)
{
	const unsigned long		base = (unsigned long)ft_strlen(map);
	const unsigned int		len = (unsigned int)ft_strlen(str);
	unsigned long			nb;
	unsigned int			p;
	int						x;

	if (!base)
		return (0);
	nb = 0;
	p = len;
	while (p--)
	{
		x = ft_strchrpos(map, str[p]);
		if (x >= 0)
			nb += (unsigned long)(x * ft_pow((int)base, (int)(len - p - 1)));
	}
	return (nb);
}
