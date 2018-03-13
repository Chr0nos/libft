/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 00:39:54 by snicolet          #+#    #+#             */
/*   Updated: 2018/03/13 15:57:34 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_getline.h"
#include <unistd.h>

static size_t		getline_read(t_getline *gl)
{
	size_t		spaceleft;
	ssize_t		readed;

	if (!(gl->flags & FT_GETL_OPEN))
		return ((size_t)ft_getline_error(gl, FT_GETL_NONE, "file is not open"));
	spaceleft = FT_GETL_BUFFSIZE - gl->buffpos;
	if (spaceleft < 2)
		return ((size_t)ft_getline_error(gl, FT_GETL_FULL,
					"no space left") + 1);
	ft_printf("possible max read: %lu\n", spaceleft - 1);
	readed = read(gl->fd, &gl->buffer[gl->buffpos], spaceleft - 1);
	if (readed < 0)
		return ((size_t)ft_getline_error(gl,FT_GETL_IOERR,
					"input/output failure") + 1);
	if (readed == 0)
	{
		ft_getline_end(gl);
		return (0);
	}
	gl->buffpos += (size_t)readed;
	gl->buffer[gl->buffpos] = '\0';
	return ((size_t)readed);
}

static int			getline_truncate(t_getline *gl, char *buffer, size_t size)
{
	size_t		cpysize = (size < gl->buffpos) ? size : gl->buffpos;

	if (cpysize)
	{
		if (gl->flags & FT_GETL_NOTRUNC)
			return (ft_getline_error(gl, FT_GETL_TRUNC, "truncate disabled"));
		ft_printf("%s", "warning: truncated read\n");
		ft_memcpy(buffer, gl->buffer, cpysize);
	}
	buffer[cpysize] = '\0';
	gl->buffpos = 0;
	gl->buffer[0] = '\0';
	gl->flags |= FT_GETL_TRUNC;
	return ((int)cpysize);
}

/*
** reads a sub part in the current storage (gl->buffer)
** endpos points to the next \n
** copy the line to "buffer" and remove this from gl->buffer with ft_memmove
*/

static int			getline_subseq(t_getline *gl, char *endpos,
		char *buffer, const size_t size)
{
	const ssize_t		readed = endpos - gl->buffer;

	if (!endpos)
		return (-1);
	if ((size_t)readed > size)
		return (getline_truncate(gl, buffer, size));
	ft_memcpy(buffer, gl->buffer, (size_t)readed);
	buffer[readed] = '\0';
	gl->buffpos -= (size_t)readed;
	ft_memmove(gl->buffer, &gl->buffer[readed + 1], gl->buffpos + 1);
	gl->buffer[gl->buffpos] = '\0';
	return ((int)readed);
}

int					ft_getline_sread(t_getline *gl,
		char *buffer, size_t size)
{
	char		*endpos;

	if ((!(gl->flags & FT_GETL_OPEN)) || (gl->flags & FT_GETL_ERROR))
		return (-1);
	if (!gl->buffpos)
		getline_read(gl);
	if (gl->buffpos > 0)
	{
		endpos = ft_strchr_old(gl->buffer, '\n');
		if (endpos)
			return (getline_subseq(gl, endpos, buffer, size));
		getline_read(gl);
		return (getline_truncate(gl, buffer, size));
	}
	ft_printf("%s", "dead end\n");
	return ((gl->flags & FT_GETL_ERROR) ? -1 : 0);
}
