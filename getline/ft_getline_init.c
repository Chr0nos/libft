/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 06:42:49 by snicolet          #+#    #+#             */
/*   Updated: 2018/04/27 00:06:45 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getline.h"
#include <unistd.h>
#include <fcntl.h>

unsigned int		ft_getline_init(t_getline *gl, const char *filepath,
		const unsigned int flags)
{
	if (FT_GETL_BUFFSIZE < 2)
	{
		gl->flags = FT_GETL_ERROR;
		return (FT_GETL_ERROR);
	}
	gl->filepath = filepath;
	gl->buffer[0] = '\0';
	gl->buffptr = &gl->buffer[FT_GETL_BUFFSIZE - 1];
	gl->flags = (flags & (FT_GETL_QUIET | FT_GETL_NOTRUNC));
	gl->fd = open(filepath, O_RDONLY);
	if (gl->fd <= 0)
	{
		ft_getline_error(gl, FT_GETL_OPENF, "failed to open.");
		return (gl->flags);
	}
	gl->flags |= FT_GETL_OPEN;
	return (FT_GETL_OK);
}
