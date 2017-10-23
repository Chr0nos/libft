/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:57:06 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/23 18:56:00 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H
# include <unistd.h>
# define MEMTINY		(size_t)(getpagesize() * 4)
# define MEMSMALL		(size_t)(getpagesize() * 32)
# define MEM_USED		(1u << 0)
# define MEM_BIG		(1u << 1)

typedef struct			s_memblock
{
	size_t				size;
	size_t				flags;
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
	size_t				count;
	t_memblock			*blocks;
}						t_mempage;

#endif


t_memblock				*ft_block_init(t_memblock *block, const size_t size);
t_mempage				*ft_page_init(t_mempage *page);
