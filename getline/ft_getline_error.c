/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 06:48:32 by snicolet          #+#    #+#             */
/*   Updated: 2018/03/13 06:49:09 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_getline.h"
#include <unistd.h>

int					ft_getline_error(t_getline *gl, unsigned int flags,
		const char *msg)
{
	gl->flags |= FT_GETL_ERROR | flags;
	if (!(gl->flags & FT_GETL_QUIET))
		ft_dprintf(STDERR_FILENO, "%s%s%s%s\n",
			"error: (", gl->filepath, "): ", msg);
	if (gl->flags & FT_GETL_OPEN)
	{
		close(gl->fd);
		gl->fd = 0;
		gl->flags &= ~FT_GETL_OPEN;
	}
	return (-1);
}
