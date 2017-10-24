#include "libft.h"
#include "ft_malloc.h"
#include <sys/mman.h>

static int		test_malloc_page(void)
{
	t_mempage	*page;
	size_t		headsize;
	size_t		realsize;

	headsize = sizeof(t_mempage) + (sizeof(t_memblock) * 200);
	ft_printf("head size: %lu\n", headsize);
	page = ft_page_create(NULL);
	if (!page)
	{
		ft_putstr("epic failure\n");
		return (1);
	}
	ft_printf("page ptr %p\nsize: %lu\nblocks: %lu\n", page, page->size, page->count);
	realsize = (size_t)page->blocks[199].content -  (size_t)page->blocks[0].content;
	ft_printf("real size: %lu\n", realsize);
	// purge de toute la zone "raw"
	ft_printf("purging %p\n", page->blocks->content);
	ft_bzero(page->blocks->content, page->size);
	ft_page_delete(page);
	return (0);
}

static void		test_malloc(void)
{
	char	*string;

	string = ft_malloc(50);
	ft_strcpy(string, "j'apprecie les fruits au sirop");
	ft_putendl(string);
}

int		main(void)
{
	test_malloc_page();
	test_malloc();
	return (0);
}
