/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:42:02 by snicolet          #+#    #+#             */
/*   Updated: 2017/11/06 03:09:24 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "libft.h"

/*
** for standards pages (non big), this function will check if the page is
** the first page (root) : if it is: we keep the root and don't free it
** in all other cases any totaly empty page will be deleted and unmaped
*/

static inline void	ft_free_emptypage(t_mempage *page)
{
	size_t		p;

	if ((page == ft_page_store(NULL, READ)) &&
			(!(page->blocks->flags & MEM_BIG)))
		return ;
	p = page->count;
	while (p--)
		if (page->blocks[p].flags & MEM_USED)
			return ;
	ft_page_delete(page);
}

static inline void	ft_free_std(t_mempage *page, t_memblock *block)
{
	block->flags &= MEM_BIG;
	block->used_size = 0;
	ft_free_emptypage(page);
}

static inline int	ft_free_loop(t_mempage *page, size_t const p,
	const void *ptr)
{
	if (page->blocks[p].content == ptr)
	{
		if (page->blocks[p].flags & MEM_BIG)
			ft_page_delete(page);
		else
			ft_free_std(page, &page->blocks[p]);
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
