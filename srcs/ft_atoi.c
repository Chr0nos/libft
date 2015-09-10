/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 14:24:21 by snicolet          #+#    #+#             */
/*   Updated: 2015/09/10 19:14:07 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_atoi(char *str)
{
	int		nb;
	int		p;
	int		len;
	char	negative;

	p = 0;
	nb = 0;
	negative = 0;
	while ((ft_strany(*str, " \t\n\v\f\r+")) && (*str))
		str++;
	if (*str == '-')
	{
		negative = 1;
		str++;
	}
	len = ft_strlen(str);
	while (str[p])
	{
		nb += (str[p] - '0') * (ft_pow(10, len - p - 1));
		p++;
	}
	if (negative)
		nb *= -1;
	return (nb);
}
