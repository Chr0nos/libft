#include "libft.h"
#include "ft_malloc.h"
#include <sys/mman.h>

int		main(void)
{
	t_mempage	*page;

	page = ft_page_create(NULL);
	if (!page)
	{
		ft_putstr("epic failure\n");
		return (1);
	}
	ft_printf("page size: %lu\nblocks: %lu\n", page->size, page->count);
	// purge de toute la zone "raw"
	ft_bzero(page->blocks->content, page->size);
	ft_page_delete(page);
}
