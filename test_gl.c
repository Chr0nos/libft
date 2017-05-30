/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 17:01:41 by snicolet          #+#    #+#             */
/*   Updated: 2017/05/29 17:04:31 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		fd;
	char	line[1024];

	fd = open(av[1], O_RDONLY);
	while (ft_gl(line, fd))
		ft_printf("line -> %s", line);
	close(fd);
}

