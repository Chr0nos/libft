#include "libft.h"
#include "ft_malloc.h"
#include <sys/mman.h>

static int		test_malloc_page(void)
{
	t_mempage	*page;
	size_t		headsize;

	headsize = sizeof(t_mempage) + (sizeof(t_memblock) * 200);
	ft_printf("head size: %lu\n", headsize);
	page = ft_page_create(NULL);
	if (!page)
	{
		ft_putstr("epic failure\n");
		return (1);
	}
	ft_printf("page ptr %p\nsize: %lu\nblocks: %lu\n", page, page->size, page->count);
	// purge de toute la zone "raw"
	ft_printf("purging %p\n", page->blocks->content);
	ft_bzero(page->blocks->content, page->size + 5744);
	ft_page_delete(page);
	return (0);
}

int		main(void)
{
	test_malloc_page();
	return (0);
}
