/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_getline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 23:40:57 by snicolet          #+#    #+#             */
/*   Updated: 2018/04/27 00:18:09 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_getline.h"
#define LINE_SIZE 100

int		main(int ac, char **av)
{
	size_t			i;
	t_getline		gl;
	char			line[LINE_SIZE];

	if (ac < 2)
		return (EXIT_FAILURE);
	if (ft_getline_init(&gl, av[1], FT_GETL_QUIET) != FT_GETL_OK)
	{
		ft_dprintf(STDERR_FILENO, "%s%s\n" "error: failed to open: ", av[1]);
		return (EXIT_FAILURE);
	}
	ft_printf("buffptr %p - buffer: %p\n", gl.buffptr, gl.buffer);
	i = 0;
	while (ft_getline_read(&gl, (t_buffer){line, LINE_SIZE}) >= 0)
		ft_printf("[%3lu] %c> %s\n", i++,
				(gl.flags & FT_GETL_TRUNC) ? '=' : '-' ,line);
	ft_printf("%s%hb\n", "exiting properly: ", gl.flags);
	ft_getline_end(&gl);
	return (EXIT_SUCCESS);
}
