/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 14:49:37 by snicolet          #+#    #+#             */
/*   Updated: 2018/02/28 15:41:30 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	long		nb;
	char		negative;

	nb = 0;
	negative = 0;
	while ((ft_strchr(" \t\v\r\v\f", *str)) && (*str))
		str++;
	if (*str == '+')
		str++;
	else if ((*str == '-') && (*(str++)))
		negative = 1;
	while (ft_isdigit(*str))
		nb = (nb * 10) + (*(str++) - '0');
	return ((negative) ? (nb * -1) : nb);
}
