/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 17:00:15 by snicolet          #+#    #+#             */
/*   Updated: 2015/10/29 23:56:45 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

char	*ft_convert_base(int nb, t_size base, char *pattern)
{
	char			*str;
	t_size			p;

	if (base < 2)
		return (0);
	str = malloc((sizeof(char) * 33));
	if ((!str) || (!pattern))
		return (0);
	p = 0;
	if (nb < 0)
	{
		nb *= -1;
		str[p++] = '-';
	}
	while (nb)
	{
		str[p] = pattern[nb % base];
		nb /= base;
		p++;
	}
	str[p] = '\0';
	return (str);
}
