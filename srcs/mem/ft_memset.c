/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:17:00 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/26 17:12:34 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*str;

	str = dest;
	while (n--)
		str[n] = c;
	return (str);
}
