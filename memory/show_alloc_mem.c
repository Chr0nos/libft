/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:05:49 by snicolet          #+#    #+#             */
/*   Updated: 2017/11/06 19:28:15 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_malloc_showtype(t_mempage *page, size_t const min,
		size_t const max, const char * name)
{
	t_memblock	*block;
	size_t		block_index;
	char		title;

	title = 0;
	block_index = 0;
	while (block_index < page->count)
	{
		block = &page->blocks[block_index];
		if ((block->flags & MEM_USED) &&
				(block->size > min) && (block->size <= max))
		{
			if (!title)
			{
				ft_printf("%s%s\n", name, " : ", block);
				title = 1;
			}
			ft_printf("%p%s%p%s%lu%s",
					block->content, " - ",
					(size_t)block->content + block->size,
					" : ", block->used_size, " octects\n");
		}
		block_index++;
	}
}

void		show_alloc_mem(void)
{
	size_t			total;
	t_mempage		*page;

	total = 0;
	page = ft_page_store(NULL, READ);
	while (page)
	{
		ft_malloc_showtype(page, 0, MEMTINY, "TINY");
		ft_malloc_showtype(page, MEMTINY, MEMSMALL, "SMALL");
		ft_malloc_showtype(page, MEMSMALL, (size_t)-1, "LARGE");
		page = page->next;
	}
	ft_printf("%s%lu\n", "Total:  ", total);
}
