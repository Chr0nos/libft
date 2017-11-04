/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:42:02 by snicolet          #+#    #+#             */
/*   Updated: 2017/11/04 14:59:25 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "libft.h"

static inline void	ft_free_std(t_memblock *block)
{
	block->flags &= MEM_BIG;
	block->used_size = 0;
}

static inline int	ft_free_loop(t_mempage *page, size_t const p,
	const void *ptr)
{
	if (page->blocks[p].content == ptr)
	{
		if (page->blocks[p].flags & MEM_BIG)
			ft_page_delete(page);
		else
			ft_free_std(&page->blocks[p]);
		return (1);
	}
	return (0);
}

void				ft_free(void *ptr)
{
	t_mempage		*page;
	size_t			p;

	page = ft_page_store(NULL, READ);
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
			if (ft_free_loop(page, p, ptr))
				return ;
		}
		page = page->next;
	}
}
