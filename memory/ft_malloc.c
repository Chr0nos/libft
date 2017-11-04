/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:55:06 by snicolet          #+#    #+#             */
/*   Updated: 2017/11/04 13:42:11 by snicolet         ###   ########.fr       */
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
		ft_printf("page informations: size: %lu - blocks count: %lu%s%p\n",
			page->size, page->count, " - address: ", page);
		p = 0;
		while (p < page->count)
		{
			block = &page->blocks[p];
			ft_printf("[%3lu]%s%p%s%6lu%s%s%s%lu\n", p,
				"\taddress: ", block->content, " - size: ", block->size,
				" - used: ", (block->flags & MEM_USED) ? "yes" : "no",
				" - used size: ", block->used_size);
			p++;
		}
		ft_putchar('\n');
		page = page->next;
	}
	ft_putstr("--- END ---\n");
}

void				*ft_malloc(size_t const size)
{
	t_mempage				*page;
	t_memblock				*block;

	page = ft_page_store(NULL);
	block = ft_block_search(page, size);
	if (block)
	{
		block->flags |= MEM_USED;
		block->used_size = size;
		return (block->content);
	}
	return (NULL);
}
