/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_getline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 23:40:57 by snicolet          #+#    #+#             */
/*   Updated: 2018/04/24 00:08:43 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_getline.h"
#define LINE_SIZE 4000

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
	i = 0;
	while (ft_getline_sread(&gl, line, LINE_SIZE) >= 0)
		ft_printf("[%3lu] -> %s\n", i++, line);
	ft_getline_end(&gl);
	ft_printf("%s", "exiting properly\n");
	return (EXIT_SUCCESS);
}
