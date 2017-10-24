#include "libft.h"
#include "ft_malloc.h"
#include <sys/mman.h>

int		main(void)
{
	t_mempage	*page;

	page = ft_page_create(NULL);
	ft_printf("page size: %lu\nblocks: %lu\n", page->size, page->count);
	munmap(page, page->size + sizeof(t_mempage) + (sizeof(t_memblock) * page->count));
}
