/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 00:39:54 by snicolet          #+#    #+#             */
/*   Updated: 2018/03/13 07:44:28 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_getline.h"
#include <fcntl.h>
#include <unistd.h>

static size_t		getline_read(t_getline *gl)
{
	size_t		spaceleft;
	ssize_t		readed;

	if (!(gl->flags & FT_GETL_OPEN))
		return (ft_getline_error(gl, FT_GETL_NONE, "file is not open"));
	spaceleft = FT_GETL_BUFFSIZE - gl->buffpos;
	if (!spaceleft)
		return (ft_getline_error(gl, FT_GETL_FULL, "no space left") + 1);
	readed = read(gl->fd, &gl->buffer[gl->buffpos], spaceleft - 1);
	if (readed < 0)
		return (ft_getline_error(gl,FT_GETL_IOERR, "input/output failure") + 1);
	if (readed == 0)
	{
		ft_printf("closing\n");
		close(gl->fd);
		gl->fd = 0;
		gl->flags &= ~FT_GETL_OPEN;
	}
	ft_printf("readed: %ld\n", readed);
	gl->buffer[readed + 1] = '\0';
	gl->buffpos += (size_t)readed;
	return ((size_t)readed);
}

static int			getline_truncate(t_getline *gl, char *buffer, size_t size)
{
	size_t		cpysize = (size < gl->buffpos) ? size : gl->buffpos;

	ft_printf("%s", "warning: truncated read\n");
	ft_memcpy(buffer, gl->buffer, cpysize);
	buffer[cpysize] = '\0';
	gl->buffpos = 0;
	gl->buffer[0] = '\0';
	gl->flags |= FT_GETL_TRUNC;
	return ((int)cpysize);
}

int					ft_getline_sread(t_getline *gl,
		char *buffer, size_t size)
{
	ssize_t		readed;
	char		*endpos;

	if ((!(gl->flags & FT_GETL_OPEN)) || (gl->flags & FT_GETL_ERROR))
		return (-1);
	if (!gl->buffpos)
		getline_read(gl);
	if (gl->buffpos > 0)
	{
		endpos = strchr(gl->buffer, '\n');
		if (endpos)
		{
			readed = endpos - gl->buffer;
			if ((size_t)readed > size)
				return (getline_truncate(gl, buffer, size));
			ft_memcpy(buffer, gl->buffer, readed);
			buffer[readed] = '\0';
			gl->buffpos -= readed;
			ft_memmove(gl->buffer, &gl->buffer[readed + 1], gl->buffpos - 1);
		//	ft_printf("seq read: %ld : %p - %p\n", readed, endpos, &gl->buffer[readed + 1]);
			return (readed);
		}
		if (getline_read(gl))
			return (ft_getline_sread(gl, buffer, size));
		ft_printf("%s %x\n", "no end", (int)*gl->buffer);
		return (0);
	}
	ft_printf("%s", "dead end\n");
	return (-1);
}
