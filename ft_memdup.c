/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:16:31 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/01 18:12:18 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	*ft_memdup(const void *src, size_t size)
{
	unsigned char	*x;

	if (!(x = malloc(size)))
		return (NULL);
	return (ft_memcpy(x, src, size));
}
