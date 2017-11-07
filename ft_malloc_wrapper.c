/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_wrapper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:03:04 by snicolet          #+#    #+#             */
/*   Updated: 2017/11/07 19:35:58 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*malloc(size_t size)
{
	return (ft_malloc(size));
}

void	free(void *ptr)
{
	ft_free(ptr);
}

void	*realloc(void *ptr, size_t size)
{
	return (ft_realloc(ptr, size));
}

void	*calloc(size_t count, size_t size)
{
	void	*ptr;

	size = count * size;
	ptr = ft_malloc(size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}
