/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 12:07:53 by snicolet          #+#    #+#             */
/*   Updated: 2017/11/09 01:38:49 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "libft.h"
#include <stdlib.h>

static inline void	*ft_realloc_core(t_memblock *block, size_t size)
{
	void	*ptr;

	pthread_mutex_unlock(&g_memlock);
	ptr = ft_malloc(size);
	if (!ptr)
	{
		ft_free(block->content);
		return (NULL);
	}
	pthread_mutex_lock(&g_memlock);
	ft_memcpy(ptr, block->content,
			(block->used_size < size) ? block->used_size : size);
	pthread_mutex_unlock(&g_memlock);
	ft_free(block->content);
	return (ptr);
}

void				*ft_realloc(void *ptr, size_t size)
{
	t_memblock	*block;
	t_mempage	*page;

	if (!ptr)
		return (ft_malloc(size));
	if (!size)
	{
		ft_free(ptr);
		ft_putendl("no size");
		return (NULL);
	}
	pthread_mutex_lock(&g_memlock);
	if (!ft_memfind(ptr, &page, &block))
	{
		pthread_mutex_unlock(&g_memlock);
		return (NULL);
	}
	if (page->blocksize >= size)
	{
		block->used_size = size;
		pthread_mutex_unlock(&g_memlock);
		return (ptr);
	}
	return (ft_realloc_core(block, size));
}
