/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:42:02 by snicolet          #+#    #+#             */
/*   Updated: 2017/11/04 13:45:50 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static inline void	ft_free_std(t_memblock *block)
{
	block->flags &= MEM_BIG;
	block->used_size = 0;
}

void				ft_free(void *ptr)
{
	t_mempage		*page;
	size_t			p;

	page = ft_page_store(NULL);
	while (page)
	{
		if ((!page->count) || (ptr < page->blocks->content) ||
			(ptr > (void*)((size_t)page->blocks->content + page->size)))
		{
			page = page->next;
			continue ;
		}
		p = page->count;
		while (p--)
		{
			if (page->blocks[p].content == ptr)
			{
				if (page->blocks[p].flags & MEM_BIG)
					return (ft_page_delete(page));
				return (ft_free_std(&page->blocks[p]));
			}
		}
		page = page->next;
	}
}
