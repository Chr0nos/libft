/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 12:07:53 by snicolet          #+#    #+#             */
/*   Updated: 2017/11/07 23:52:10 by snicolet         ###   ########.fr       */
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
	{
		ft_putendl("failed to allocate memory");
		ft_free(block->content);
		return (NULL);
	}
	ft_memcpy(ptr, block->content,
			(block->used_size < size) ? block->used_size : size);
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
	if (!ft_memfind(ptr, &page, &block))
	{
		ft_printf("%s%p\n", "realloc cannot found the folowing pointer: ", ptr);
		show_alloc_mem();
		return (NULL);
	}
	if (page->blocksize >= size)
	{
		block->used_size = size;
		return (ptr);
	}
	return (ft_realloc_core(block, size));
}
