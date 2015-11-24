/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 17:00:15 by snicolet          #+#    #+#             */
/*   Updated: 2015/10/31 01:56:36 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
	if (nb == 0)
		str[p++] = pattern[0];
	else if (nb < 0)
	{
		nb *= -1;
		str[p++] = '-';
	}
	while (nb)
	{
		str[p++] = pattern[nb % base];
		nb /= base;
	}
	str[p] = '\0';
	ft_strrev(str);
	return (str);
}
