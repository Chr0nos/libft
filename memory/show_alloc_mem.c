/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:05:49 by snicolet          #+#    #+#             */
/*   Updated: 2017/11/10 17:32:01 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*gettitle(size_t const size)
{
	if (size == MEMTINY)
		return ("TINY");
	else if (size == MEMSMALL)
		return ("SMALL");
	return ("LARGE");
}

void				show_alloc_mem(void)
{
	size_t		total;
	size_t		p;
	t_mempage	*page;
	t_memblock	*block;

	total = 0;
	page = ft_page_store(NULL, READ);
	while (page)
	{
		ft_printf("%s%s%p\n", gettitle(page->blocksize), " : ", page);
		p = 0;
		while (p < page->count)
		{
			block = &page->blocks[p++];
			if (block->used_size > 0)
				ft_printf("%p%s%p%s%lu%s", block->content, " - ",
					(size_t)block->content + page->blocksize,
					" : ", block->used_size, " octects\n");
		}
		page = page->next;
	}
	ft_printf("%s%lu%s", "Total : ", total, " octects\n");
}
