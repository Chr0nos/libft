/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitstobuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:54:55 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/05 18:01:33 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_bitstobuff(char *buff, unsigned long long x, const int n)
{
	int		p;

	p = 0;
	while (p < n)
		*(buff++) = (x & (1u >> (n - p++))) ? '1' : 0;
	return (n);
}
