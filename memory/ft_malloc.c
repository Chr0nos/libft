/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:55:06 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/24 17:49:45 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "libft.h"
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
	block->content = NULL;
	return (block);
}

void			ft_block_init_many(t_mempage *page, void *raw,
	size_t const blocksize, size_t count)
{
	t_memblock		*block;
	size_t			p;

	block = page->blocks;
	p = 0;
	while (count--)
	{
		ft_block_init(block, blocksize);
		block->content = raw;
		raw = (void*)((size_t)raw + blocksize);
		block++;
	}
}

/*
** memory management implementation:
**    page  | blocks (meta)  |     raw memory pointed by blocks contents  |
** |--------|----------------|--------------------------------------------|
** |   1    |       200      |                                            |
** |--------|----------------|--------------------------------------------|
** |                                SIZE                                  |
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
	// taille totale de la zone memoire a allouer
	size = rawsize + (sizeof(t_memblock) * 200) + sizeof(t_mempage);
	memory = mmap(NULL, size, PROT_WRITE | PROT_READ, MAP_PRIVATE | MAP_ANON, -1, 0);
	if (!memory)
		return (NULL);
	// la page est la premiere partie de la zone
	page = (t_mempage*)(size_t)memory;
	page->blocks = (t_memblock*)((size_t)page + sizeof(t_mempage));
	ft_bzero(page, sizeof(t_mempage));
	page->count = 200;
	page->size = rawsize;
	raw = (void*)((size_t)page->blocks + (sizeof(t_memblock) * page->count));
	ft_block_init_many(page, raw, MEMSMALL, 100);
	raw = (void*)((size_t)raw + (MEMSMALL * 100));
	ft_block_init_many(page, raw, MEMTINY, 100);
	page->prev = parent;
	if (parent)
		parent->next = page;
	return (page);
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
