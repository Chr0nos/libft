/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:42:02 by snicolet          #+#    #+#             */
/*   Updated: 2017/11/09 02:21:42 by snicolet         ###   ########.fr       */
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
			(page->blocksize <= MEMSMALL))
		return ;
	p = page->count;
	while (p--)
		if (page->blocks[p].used_size)
			return ;
	ft_page_delete(page);
}

void				ft_free(void *ptr)
{
	t_mempage		*page;
	t_memblock		*block;
	pthread_mutex_t	*lock;

	lock = ft_memlock();
	pthread_mutex_lock(lock);
	if (!ft_memfind(ptr, &page, &block))
	{
		pthread_mutex_unlock(lock);
		return ;
	}
	if (page->blocksize > MEMSMALL)
		ft_page_delete(page);
	else
	{
		block->used_size = 0;
		ft_free_emptypage(page);
	}
	pthread_mutex_unlock(lock);
}
