/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 13:58:38 by snicolet          #+#    #+#             */
/*   Updated: 2017/03/04 11:08:46 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_sqrt(float nb)
{
	float	xhalf;
	int		i;

	i = *(int*)(void*)(size_t)&nb;
	xhalf = 0.5f * nb;
	i = 0x5f3759df - (i >> 1);
	nb = *(float*)(size_t)&i;
	nb = nb * (1.5f - xhalf * nb * nb);
	return (nb);
}
