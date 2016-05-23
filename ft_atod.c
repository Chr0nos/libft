/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 20:19:56 by snicolet          #+#    #+#             */
/*   Updated: 2016/05/23 20:34:11 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(const char *s)
{
	double		nb;
	char		negative;
	double		lvl;

	nb = 0.0;
	while ((ft_strany(*s, " \t\n\v\f\r")) && (*s))
		s++;
	negative = 0;
	if (*s == '+')
		s++;
	else if ((*s == '-') && (*(s++)))
		negative = 1;
	while (ft_isdigit(*s))
		nb = (nb * 10) + (*(s++) - '0');
	if (*s != '.')
		return ((negative) ? (nb * -1) : nb);
	s++;
	lvl = 10.0;
	while ((*s) && (ft_isdigit(*s)))
	{
		nb += (double)((*(s++)) - '0') / lvl;
		lvl *= 10.0;
	}
	return ((negative) ? (nb * -1) : nb);
}
