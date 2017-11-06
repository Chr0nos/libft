/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_page.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 03:09:06 by snicolet          #+#    #+#             */
/*   Updated: 2017/11/06 03:03:06 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/mman.h>

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
	page->blocks->used_size = size;
	page->blocks->content = (void*)((size_t)page->blocks + sizeof(t_memblock));
	return (page);
}

/*
** permanently delete a memory page, ensure to keep the page list coherent
** the page will check the previous page and link it's next pointer to the
** page next if any (otherwise a NULL will be set)
** on MEM_BIG pages this is the default behavior
*/

void				ft_page_delete(t_mempage *page)
{
	const t_mempage		*root = ft_page_store(NULL, READ);

	if (page == root)
	{
		ft_page_store(page->next, WRITE);
	}
	if (page->prev)
		page->prev->next = page->next;
	if (page->next)
		page->next->prev = page->prev;
	munmap(page, page->size + sizeof(t_mempage) +
		(sizeof(t_memblock) * page->count));
}

t_mempage			*ft_page_add(t_mempage *page)
{
	t_mempage	*root;

	if (!page)
		return (NULL);
	root = ft_page_store(NULL, READ);
	if (!root)
	{
		ft_page_store(page, WRITE);
		return (page);
	}
	while (root->next)
		root = root->next;
	root->next = page;
	page->prev = root;
	return (page);
}

t_mempage			*ft_page_store(t_mempage *userpage, t_malloc_mode mode)
{
	static t_mempage		*page = NULL;

	if (mode == WRITE)
		page = userpage;
	return (page);
}