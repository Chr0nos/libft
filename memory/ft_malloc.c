/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:55:06 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/26 02:33:55 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "libft.h"
#include <sys/mman.h>

/*
** configure a block of "size" and return the block address
** returns the block itself
*/

t_memblock			*ft_block_init(t_memblock *block, const size_t size)
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

void				*ft_block_init_many(t_memblock *block, void *raw,
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
** order of raw data: (in a classical page not a big one)
** MEMSMALL -> MEMTINY
*/

t_mempage			*ft_page_create(void)
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
	raw = ft_block_init_many(page->blocks, raw, MEMSMALL, 100);
	ft_block_init_many(&page->blocks[100], raw, MEMTINY, 100);
	return (page);
}

t_mempage			*ft_page_create_big(size_t const size)
{
	size_t		fullsize;
	void		*memory;
	t_mempage	*page;

	fullsize = sizeof(t_mempage) + sizeof(t_memblock) + size;
	memory = mmap(NULL, fullsize, PROT_READ | PROT_WRITE,
		MAP_PRIVATE | MAP_ANON, -1, 0);
	if (!memory)
		return (NULL);
	page = (t_mempage*)(size_t)memory;
	ft_bzero(page, sizeof(t_mempage));
	page->count = 1;
	page->size = size;
	page->blocks = (t_memblock*)((size_t)page + sizeof(t_mempage));
	page->blocks->size = size;
	page->blocks->flags = MEM_BIG;
	page->blocks->content = (void*)((size_t)page->blocks + sizeof(t_memblock));
	return (page);
}

void				ft_page_delete(t_mempage *page)
{
	if (page == ft_page_store(NULL))
		ft_page_store(page->next);
	if (page->prev)
		page->prev = page->next;
	if (page->next)
		page->next->prev = page->prev;
	munmap(page, page->size + sizeof(t_mempage) +
		(sizeof(t_memblock) * page->count));
}

t_mempage			*ft_page_store(t_mempage *userpage)
{
	static t_mempage		*page = NULL;

	if (userpage)
		page = userpage;
	return (page);
}

t_mempage			*ft_page_add(t_mempage *page)
{
	t_mempage	*root;

	if (!page)
		return (NULL);
	root = ft_page_store(NULL);
	if (!root)
	{
		ft_page_store(page);
		return (page);
	}
	while (root->next)
		root = root->next;
	root->next = page;
	page->prev = root;
	return (page);
}

t_memblock			*ft_block_search(t_mempage *page, size_t const size)
{
	size_t			p;
	t_memblock		*block;

	while (page)
	{
		p = page->count;
		while (p--)
		{
			block = &page->blocks[p];
			if (block->flags & (MEM_BIG | MEM_DISABLED | MEM_USED))
				continue ;
			if (block->size >= size)
				return (block);
		}
		page = page->next;
	}
	page = ft_page_create();
	if (page)
		return (page->blocks);
	return (NULL);
}

void				ft_malloc_display(void)
{
	t_mempage	*page;
	t_memblock	*block;
	size_t		p;

	ft_putstr("--- START ---\n");
	page = ft_page_store(NULL);
	while (page)
	{
		ft_printf("page informations: size: %lu - blocks count: %lu\n",
			page->size, page->count);
		p = 0;
		while (p < page->count)
		{
			block = &page->blocks[p];
			ft_printf("[%3lu]%s%p%s%6lu%s%s\n", p,
				"\taddress: ", block->content,
				" - size: ", block->size,
				" - used: ", (block->flags & MEM_USED) ? "yes" : "no");
			p++;
		}
		page = page->next;
	}
	ft_putstr("--- END ---\n");
}

static inline void 	*ft_malloc_big(size_t const size)
{
	t_memblock	*block;
	t_mempage	*page;

	page = ft_page_create_big(size);
	if (page)
	{
		ft_page_add(page);
		block = page->blocks;
		block->flags |= MEM_USED;
		return (block);
	}
	return (NULL);
}

void				*ft_malloc(size_t const size)
{
	t_mempage				*page;
	t_memblock				*block;

	page = ft_page_store(NULL);
	if (!page)
	{
		if (size > MEMSMALL)
			ft_page_add(ft_page_create_big(size));
		else
			ft_page_add(ft_page_create());
	}
	else if (size > MEMSMALL)
		return (ft_malloc_big(size));
	block = ft_block_search(page, size);
	if (block)
	{
		block->flags |= MEM_USED;
		return (block->content);
	}
	return (NULL);
}
