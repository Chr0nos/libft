/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:55:06 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/24 23:22:27 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "libft.h"
#include <sys/mman.h>

/*
** configure a block of "size" and return the block address
** returns the block itself
*/

t_memblock		*ft_block_init(t_memblock *block, const size_t size)
{
	block->size = size;
	block->flags = 0;
	if (size > MEMSMALL)
		block->flags = MEM_BIG;
	block->content = NULL;
	return (block);
}

/*
** intitialize "count" blocks of "blocksize" contained into "page"
** returns the next "free" raw block (for others calls to this)
*/

void			*ft_block_init_many(t_memblock *block, void *raw,
	size_t const blocksize, size_t count)
{
	while (count--)
	{
		ft_block_init(block, blocksize);
		block->content = raw;
		raw = (void*)((size_t)raw + blocksize);
		block++;
	}
	return (raw);
}

/*
** memory management implementation:
** t_mempage| t_memblock[]   |
**    page  | blocks (meta)  |     raw memory pointed by blocks contents  |
** |--------|----------------|--------------------------------------------|
** |   1    |       200      |        pointed by blocks->content          |
** |--------|----------------|--------------------------------------------|
** |                                SIZE   (all the mapped memory size)   |
** |        METADATA         |   (MEMTINY + MEMSMALL) or BIG  (rawsize)   |
** |--------|----------------|--------------------------------------------|
*/

t_mempage		*ft_page_create(t_mempage *parent)
{
	size_t			rawsize;
	size_t			size;
	void			*memory;
	void			*raw;
	t_mempage		*page;

	rawsize = (MEMTINY * 100) + (MEMSMALL * 100);
	size = rawsize + (sizeof(t_memblock) * 200) + sizeof(t_mempage);
	memory = mmap(NULL, size, PROT_WRITE | PROT_READ, MAP_PRIVATE | MAP_ANON,
		-1, 0);
	if (!memory)
		return (NULL);
	page = (t_mempage*)(size_t)memory;
	ft_bzero(page, sizeof(t_mempage));
	page->blocks = (t_memblock*)((size_t)page + sizeof(t_mempage));
	page->count = 200;
	page->size = rawsize;
	raw = (void*)((size_t)page->blocks + (sizeof(t_memblock) * page->count));
	ft_printf("first raw: %p\n", raw);
	raw = ft_block_init_many(page->blocks, raw, MEMSMALL, 100);
	ft_block_init_many(&page->blocks[100], raw, MEMTINY, 100);
	page->prev = parent;
	if (parent)
		parent->next = page;
	return (page);
}

void			ft_page_delete(t_mempage *page)
{
	if (page->prev)
		page->prev = page->next;
	if (page->next)
		page->next->prev = page->prev;
	munmap(page, page->size + sizeof(t_mempage) +
		(sizeof(t_memblock) * page->count));
}

void			*ft_malloc(size_t const size)
{
	static t_mempage		*page = NULL;

	(void)size;
	if (!page)
	{
		page = ft_page_create(NULL);
	}
	return (NULL);
}
