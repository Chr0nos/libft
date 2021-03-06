/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:55:06 by snicolet          #+#    #+#             */
/*   Updated: 2017/11/12 18:23:39 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "libft.h"

void				ft_malloc_display(void)
{
	t_mempage	*page;
	t_memblock	*block;
	size_t		p;
	size_t		index;

	index = 0;
	ft_putstr("--- START ---\n");
	page = ft_page_store(NULL, READ);
	while (page)
	{
		ft_printf("page %u informations: size: %lu - blocks count: %lu%s%p\n",
			index++, page->size, page->count, " - address: ", page, p = 0);
		while (p < page->count)
		{
			block = &page->blocks[p];
			ft_printf("[%3lu]%s%p%s%6lu%s%s%s%lu\n", p,
				"\taddress: ", block->content, " - size: ", page->blocksize,
				" - used: ", (block->used_size > 0) ? "yes" : "no",
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
	pthread_mutex_t			*lock;

	if (!size)
		return (NULL);
	lock = ft_memlock();
	pthread_mutex_lock(lock);
	page = ft_page_store(NULL, READ);
	block = ft_block_search(page, size);
	if (block)
	{
		block->used_size = size;
		pthread_mutex_unlock(lock);
		return (block->content);
	}
	pthread_mutex_unlock(lock);
	return (NULL);
}
