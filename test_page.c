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
	page = ft_page_create(MEMSMALL, 100);
	if (!page)
	{
		ft_putstr("epic failure\n");
		return (1);
	}
	ft_printf("page ptr %p\nsize: %lu\nblocks: %lu\n", page, page->size, page->count);
	realsize = page->size;
	ft_printf("real size: %lu\n", realsize);
	// purge de toute la zone "raw"
	ft_bzero(page->blocks->content, realsize);
	ft_printf("purging %p\n", page->blocks->content);
	//ft_bzero(page->blocks->content, page->size);
	ft_printf("deleting page\n");
	ft_page_delete(page);
	ft_printf("done\n");
	return (0);
}

static void		test_malloc(void)
{
	char	*string;
	void	*ptrs[4];

	string = ft_malloc(50);
	ft_strcpy(string, "j'apprecie les fruits au sirop");
	ft_putendl(string);
	ft_bzero(ptrs, sizeof(void*) * 4);
	ptrs[0] = ft_malloc(MEMSMALL + 1);
	ptrs[1] = ft_malloc(MEMSMALL + 2);
	ptrs[2] = ft_malloc(16);
	ptrs[3] = ft_malloc(MEMSMALL);
	ft_printf("%s%p %p %p %p\n",
		"test pointers: ",  ptrs[0], ptrs[1], ptrs[2], ptrs[3]);
	// ft_malloc_display();
	show_alloc_mem();
	ft_free(ptrs[0]);
	ft_free(ptrs[1]);
	ft_free(ptrs[2]);
	ft_free(ptrs[3]);
	ft_free(string);
//	ft_malloc_display();
}

int		main(void)
{
	ft_printf("page size: %lu\n", getpagesize());
	ft_printf("tiny: %lu - small: %lu\n", MEMTINY, MEMSMALL);
	(void)test_malloc_page;
	test_malloc_page();
	test_malloc();
	return (0);
}
