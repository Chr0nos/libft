/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 12:07:53 by snicolet          #+#    #+#             */
/*   Updated: 2017/05/28 21:08:18 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t size, size_t new_size)
{
	void			*dest;

	if (new_size < size)
		return (0);
	dest = malloc(new_size);
	if (!dest)
		return (0);
	ft_memcpy(dest, ptr, size);
	free(ptr);
	return (dest);
}
