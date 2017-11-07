/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:57:06 by snicolet          #+#    #+#             */
/*   Updated: 2017/11/07 23:37:18 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H
# include <unistd.h>
# define MEMTINY		128
# define MEMSMALL		1024
# define MEM_USED		(1u << 0)
# define MEM_BIG		(1u << 1)
# define MEM_DISABLED	(1u << 2)

typedef enum			e_malloc_mode
{
	READ,
	WRITE
}						t_malloc_mode;

typedef struct			s_memblock
{
	size_t				used_size;
	void				*content;
}						t_memblock;

/*
** a page contains blocks and pointers to the next and previous page,
** count contains the number of blocks in the current page
** blocks can contains MEMSMALL + MEMTINY OR larger blocks,
** to know if the block is a big one check the flags on the memblock with
** MEM_BIG
*/

typedef struct			s_mempage
{
	struct s_mempage	*prev;
	struct s_mempage	*next;
	size_t				size;
	size_t				count;
	size_t				blocksize;
	t_memblock			*blocks;
}						t_mempage;

/*
** blocks management
*/

void					*ft_block_init(t_memblock *block, void *raw,
	size_t const blocksize, size_t count);
t_memblock				*ft_block_search(t_mempage *page, size_t const size);

/*
** pages management
*/

t_mempage				*ft_page_create(size_t size, size_t amount);
t_mempage				*ft_page_create_big(size_t const size);
void					ft_page_delete(t_mempage *page);
t_mempage				*ft_page_store(t_mempage *userpage, t_malloc_mode mode);
t_mempage				*ft_page_add(t_mempage *page);

/*
** public functions
*/

void					ft_free(void *ptr);
void					ft_malloc_display(void);
void					show_alloc_mem(void);
void					*ft_malloc(size_t const size);
void					*ft_realloc(void *ptr, size_t size);
int						ft_memfind(void *ptr,
		t_mempage **upage, t_memblock **ublock);

#endif
