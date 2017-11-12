/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_page.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 03:09:06 by snicolet          #+#    #+#             */
/*   Updated: 2017/11/12 18:57:07 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/mman.h>

/*
** memory management implementation:
** t_mempage| t_memblock[]   |
**    page  | blocks (meta)  |     raw memory pointed by blocks contents  |
** |--------|----------------|--------------------------------------------|
** |   1    |       100      |        pointed by blocks->content          |
** |--------|----------------|--------------------------------------------|
** |                                                                      |
** |        METADATA         |    MEMTINY or MEMSMALL or BIG  (rawsize)   |
** |  48    |       [16]     |            size * amount                   |
** |--------|----------------|--------------------------------------------|
** there is a number of "blocks" equal to the number of items in the page
** the page/blocks memory region is phisicaly continue
** the raw memory part is also continue so an overlfow won't affect metadata
** size = the size of ONE block raw
** amount = the amount of requested blocks
** in the function amount is incremented to prevent memory lost
** due to the multiple of getpagesize, the function will allocate "at last"
** the amount of blocks, and the extra size will be available too.
*/

static inline t_mempage	*ft_page_init(t_mempage *page, size_t const size,
	size_t const amount, size_t realsize)
{
	if (!page)
		return (NULL);
	ft_bzero(page, sizeof(*page));
	page->count = amount;
	page->size = realsize - (size * amount);
	page->blocks = (t_memblock*)((size_t)page + sizeof(t_mempage));
	page->blocksize = size;
	ft_block_init(page->blocks, (void*)((size_t)page->blocks +
		(sizeof(t_memblock) * amount)), size, amount);
	return (page);
}

t_mempage				*ft_page_create(size_t size, size_t amount)
{
	const size_t	pagesize = (size_t)getpagesize();
	size_t			realsize;
	size_t			neededsize;
	void			*memory;

	if ((!amount) || (!size))
		return (NULL);
	realsize = pagesize;
	neededsize = (size + sizeof(t_memblock)) * amount + sizeof(t_mempage);
	while (realsize < neededsize)
		realsize += pagesize;
	if (size <= MEMSMALL)
		amount += (realsize - neededsize) / (sizeof(t_memblock) + size);
	memory = mmap(NULL, realsize, PROT_WRITE | PROT_READ,
		MAP_PRIVATE | MAP_ANON, -1, 0);
	return (ft_page_init((t_mempage*)(size_t)memory, size, amount, realsize));
}

/*
** permanently delete a memory page, ensure to keep the page list coherent
** the page will check the previous page and link it's next pointer to the
** page next if any (otherwise a NULL will be set)
** on MEM_BIG pages this is the default behavior
*/

void					ft_page_delete(t_mempage *page)
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

t_mempage				*ft_page_add(t_mempage *page)
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

t_mempage				*ft_page_store(t_mempage *userpage, t_malloc_mode mode)
{
	static t_mempage		*page = NULL;

	if (mode == WRITE)
		page = userpage;
	return (page);
}
