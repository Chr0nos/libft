/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_getline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 23:40:57 by snicolet          #+#    #+#             */
/*   Updated: 2018/04/27 02:09:26 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_getline.h"
#define LINE_SIZE 100

static int	test_std(const char *filepath, t_buffer buffer)
{
	t_getline		gl;
	size_t			i;

	if (ft_getline_init(&gl, filepath, FT_GETL_NONE) != FT_GETL_OK)
		return (EXIT_FAILURE);
	i = 0;
	while (ft_getline_read(&gl, buffer) >= 0)
		ft_printf("[%3lu] %c> %s\n", i++,
				(gl.flags & FT_GETL_TRUNC) ? '=' : '-' ,buffer.data);
	ft_printf("%s%hb - %lu\n", "exiting properly: ", gl.flags, gl.reads);
	ft_getline_end(&gl);
	return (EXIT_SUCCESS);
}

int		main(int ac, char **av)
{
	char			line[LINE_SIZE];

	if (ac < 2)
		return (EXIT_FAILURE);
	test_std(av[1], (t_buffer){line, LINE_SIZE});
	return (EXIT_SUCCESS);
}
