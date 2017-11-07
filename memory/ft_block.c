/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_block.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 03:10:38 by snicolet          #+#    #+#             */
/*   Updated: 2017/11/07 23:42:02 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** intitialize "count" blocks of "blocksize" contained into "page"
** returns the next "free" raw block (for others calls to this)
*/

void				*ft_block_init(t_memblock *block, void *raw,
	size_t const blocksize, size_t count)
{
	while (count--)
	{
		block->content = raw;
		raw = (void*)((size_t)raw + blocksize);
		block++;
	}
	return (raw);
}

static inline t_memblock	*ft_block_search_big(size_t const size)
{
	t_mempage	*bigpage;

	bigpage = ft_page_create(size, 1);
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
		if (page->blocksize < size)
		{
			page = page->next;
			continue ;
		}
		p = page->count;
		while (p--)
		{
			block = &page->blocks[p];
			if (!block->used_size)
				return (block);
		}
		page = page->next;
	}
	page = ft_page_add(
		ft_page_create((size <= MEMTINY) ? MEMTINY : MEMSMALL , 100));
	if (page)
		return (ft_block_search(page, size));
	return (NULL);
}
