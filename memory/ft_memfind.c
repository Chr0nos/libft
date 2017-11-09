/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 23:35:23 by snicolet          #+#    #+#             */
/*   Updated: 2017/11/09 01:34:47 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static int	ft_memfind_load(t_mempage *page, t_memblock *block,
		t_mempage **upage, t_memblock **ublock)
{
	if (upage)
		*upage = page;
	if (ublock)
		*ublock = block;
	return (1);
}

/*
** find the origin of "ptr" into ft_malloc memory manager,
** if found the function will return 1 (0 otherwise)
** then set page and block into the users pointers if set, in case of both
** NULL users pointers the function just return the 0 or 1 and set nothink
** WARNING: if you need to use ft_memfind in a non-threaded software it will be
** ok but in case of threads you MUST lock the mutex g_memlock before the calls
** and unlocked it just after
*/

int			ft_memfind(void *ptr, t_mempage **upage, t_memblock **ublock)
{
	t_mempage	*page;
	size_t		block_index;

	page = ft_page_store(NULL, READ);
	while (page)
	{
		if ((ptr < page->blocks->content) ||
			(ptr > (void*)((size_t)page->blocks->content +
			(page->count * page->blocksize))))
		{
			page = page->next;
			continue ;
		}
		block_index = page->count;
		while (block_index--)
		{
			if (ptr == page->blocks[block_index].content)
				return (ft_memfind_load(page, &page->blocks[block_index],
							upage, ublock));
		}
		page = page->next;
	}
	return (0);
}
