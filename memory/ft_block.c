/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_block.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 03:10:38 by snicolet          #+#    #+#             */
/*   Updated: 2017/11/04 14:20:06 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static inline t_memblock	*ft_block_search_big(size_t const size)
{
	t_mempage	*bigpage;

	bigpage = ft_page_create_big(size);
	if (!bigpage)
		return (NULL);
	ft_page_add(bigpage);
	return (bigpage->blocks);
}

t_memblock			*ft_block_search(t_mempage *page, size_t const size)
{
	size_t			p;
	t_memblock		*block;

	if (size > MEMSMALL)
		return (ft_block_search_big(size));
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
	page = ft_page_add(ft_page_create());
	if (page)
		return (ft_block_search(page, size));
	return (NULL);
}
