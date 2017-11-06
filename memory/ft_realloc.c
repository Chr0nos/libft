/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 12:07:53 by snicolet          #+#    #+#             */
/*   Updated: 2017/11/07 00:21:36 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "libft.h"
#include <stdlib.h>

static inline void	*ft_realloc_core(t_memblock *block, size_t size)
{
	void	*ptr;

	ptr = ft_malloc(size);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, block->content, block->used_size);
	ft_free(block->content);
	return (ptr);
}

void				*ft_realloc(void *ptr, size_t size)
{
	t_memblock	*block;

	if (!ptr)
		return (ft_malloc(size));
	if (!size)
	{
		ft_free(ptr);
		return (NULL);
	}
	if (!ft_memfind(ptr, NULL, &block))
		return (NULL);
	if (block->size <= size)
	{
		block->used_size = size;
		return (ptr);
	}	
	return (ft_realloc_core(block, size));
}
