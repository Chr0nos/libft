/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 14:49:37 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/16 14:52:05 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	long		nb;
	char		negative;

	nb = 0;
	negative = 0;
	while ((ft_strany(*str, " \t\n\v\f\r")) && (*str))
		str++;
	if (*str == '+')
		str++;
	else if ((*str == '-') && (*(str++)))
		negative = 1;
	while (ft_isdigit(*str))
		nb = (nb * 10) + (*(str++) - '0');
	return ((negative) ? (nb * -1) : nb);
}
