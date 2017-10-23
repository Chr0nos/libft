/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:55:06 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/23 20:15:11 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include <sys/mman.h>

/*
** configure a block of "size" and return the block address
*/

t_memblock		*ft_block_init(t_memblock *block, const size_t size)
{
	block->size = size;
	block->flags = 0;
	if (size > MEMSMALL)
		block->flags = MEM_BIG;
	block->content = (void*)((size_t)block + sizeof(block->flags) +
		sizeof(block->size) + sizeof(block->content));
	return (block);
}

t_mempage		*ft_page_init(t_mempage *page)
{
	page->count = 0;
	page->prev = NULL;
	page->next = NULL;
	page->blocks = NULL;
	return (page);
}

t_mempage		*ft_page_create()
{
	size_t			size;
	void			*memory;
	t_mempage		*page;
	t_memblock		*blocks;

	size = (MEMTINY * 100) + (MEMSMALL * 100);
	memory = mmap(NULL, size, PROT_WRITE | PROT_READ, MAP_PRIVATE, -1, 0);
	blocks = memory + sizeof(t_mempage);
	page = (t_mempage*)(size_t)memory;
	page->blocks = blocks;
	ft_page_init(page);
	return (page);
}

void			*ft_malloc(size_t const size)
{
	static t_mempage		*page = NULL;

	(void)size;
	if (!page)
	{
		page = ft_page_create();
	}
	return (NULL);
}
