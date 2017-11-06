/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:05:49 by snicolet          #+#    #+#             */
/*   Updated: 2017/11/06 22:34:42 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	ft_malloc_showtype_title(char *title, const char *name,
		const void *ptr)
{
	if (!*title)
	{
		ft_printf("%s%s\n", name, " : ", ptr);
		*title = 1;
	}

}

static size_t		ft_malloc_showtype(t_mempage *page, size_t const min,
		size_t const max, const char * name)
{
	t_memblock	*block;
	size_t		block_index;
	size_t		total;
	char		title;

	total = 0;
	title = 0;
	block_index = 0;
	while (block_index < page->count)
	{
		block = &page->blocks[block_index];
		if ((block->flags & MEM_USED) &&
				(block->size > min) && (block->size <= max))
		{
			ft_malloc_showtype_title(&title, name, block);
			ft_printf("%p%s%p%s%lu%s",
					block->content, " - ",
					(size_t)block->content + block->size,
					" : ", block->used_size, " octects\n");
			total += block->used_size;
		}
		block_index++;
	}
	return (total);
}

void		show_alloc_mem(void)
{
	size_t			total;
	t_mempage		*page;

	total = 0;
	page = ft_page_store(NULL, READ);
	while (page)
	{
		total += ft_malloc_showtype(page, 0, MEMTINY, "TINY") +
			ft_malloc_showtype(page, MEMTINY, MEMSMALL, "SMALL") +
			ft_malloc_showtype(page, MEMSMALL, (size_t)-1, "LARGE");
		page = page->next;
	}
	ft_printf("%s%lu%s", "Total : ", total, " octects\n");
}
