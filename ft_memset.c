/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:17:00 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/12 21:35:52 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*str;
	size_t			p;

	str = dest;
	p = 0;
	while (p < n)
		str[p++] = (unsigned char)c;
	return (str);
}
