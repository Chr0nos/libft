/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:55:06 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/26 03:11:11 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "libft.h"

void				ft_malloc_display(void)
{
	t_mempage	*page;
	t_memblock	*block;
	size_t		p;

	ft_putstr("--- START ---\n");
	page = ft_page_store(NULL);
	while (page)
	{
		ft_printf("page informations: size: %lu - blocks count: %lu\n",
			page->size, page->count);
		p = 0;
		while (p < page->count)
		{
			block = &page->blocks[p];
			ft_printf("[%3lu]%s%p%s%6lu%s%s\n", p,
				"\taddress: ", block->content,
				" - size: ", block->size,
				" - used: ", (block->flags & MEM_USED) ? "yes" : "no");
			p++;
		}
		page = page->next;
	}
	ft_putstr("--- END ---\n");
}

static inline void 	*ft_malloc_big(size_t const size)
{
	t_memblock	*block;
	t_mempage	*page;

	page = ft_page_create_big(size);
	if (page)
	{
		ft_page_add(page);
		block = page->blocks;
		block->flags |= MEM_USED;
		return (block);
	}
	return (NULL);
}

void				*ft_malloc(size_t const size)
{
	t_mempage				*page;
	t_memblock				*block;

	page = ft_page_store(NULL);
	if (!page)
	{
		if (size > MEMSMALL)
			ft_page_add(ft_page_create_big(size));
		else
			ft_page_add(ft_page_create());
	}
	else if (size > MEMSMALL)
		return (ft_malloc_big(size));
	block = ft_block_search(page, size);
	if (block)
	{
		block->flags |= MEM_USED;
		return (block->content);
	}
	return (NULL);
}
