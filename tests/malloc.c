/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 20:46:18 by snicolet          #+#    #+#             */
/*   Updated: 2018/02/11 21:28:16 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <pthread.h>
#define THREADS_COUNT 420
#define ALLOC_SIZE 1024
#define THREAD_OK 0

static void		*thread_occur(void *ptr)
{
	void	*test;

	if (!(test = ft_malloc(ALLOC_SIZE)))
	{
		ft_dprintf(STDERR_FILENO, "%s%p\n", "failed to malloc in: ", ptr);
		return (NULL);
	}
	ft_bzero(test, ALLOC_SIZE);
	sleep(1);
	ft_free(test);
	ft_printf("thread id %4u : test passed\n", (unsigned int)(size_t)ptr);
	return (ptr);
}

int				main(void)
{
	pthread_t		threads[THREADS_COUNT];
	int				index;

	ft_printf("%s\n", "starting malloc multi-threads tests...");
	ft_bzero(threads, sizeof(pthread_t) * THREADS_COUNT);
	index = THREADS_COUNT;
	while (index--)
	{
		if (pthread_create(&threads[index], NULL, &thread_occur,
					(void*)(size_t)index) == THREAD_OK)
			ft_printf("thread %4u ready\n", (unsigned int)index);
		else
		{
			ft_dprintf(STDERR_FILENO,
					"%s%d\n", "error: failed to create thread: ", index);
			break ;
		}
	}
	sleep(2);
	ft_printf("%s\n", "joining threads");
	index = THREADS_COUNT;
	while (index--)
		pthread_join(threads[index], NULL);
	ft_malloc_display();
	return (EXIT_SUCCESS);
}
