/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 00:39:54 by snicolet          #+#    #+#             */
/*   Updated: 2018/04/27 02:58:43 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_getline.h"
#include <unistd.h>
#include <fcntl.h>

unsigned int	ft_getline_init(t_getline *gl, const char *filepath,
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
	if (!(flags & (FT_GETL_QUIET | FT_GETL_STDIN)))
		ft_printf("openning \"%s\" ...\n", (filepath) ? filepath : "stdin");
	gl->fd = (filepath) ? open(filepath, O_RDONLY) : STDIN_FILENO;
	if (gl->fd < 0)
	{
		ft_getline_error(gl, FT_GETL_OPENF, "failed to open.");
		return (gl->flags);
	}
	else if (gl->fd == STDIN_FILENO)
		gl->flags |= FT_GETL_STDIN;
	gl->flags |= FT_GETL_OPEN;
	gl->reads = 0;
	return (FT_GETL_OK);
}

void			ft_getline_end(t_getline *gl)
{
	if (gl->flags & FT_GETL_OPEN)
	{
		if (gl->fd != STDIN_FILENO)
			close(gl->fd);
		gl->fd = 0;
		gl->flags &= ~FT_GETL_OPEN;
	}
	gl->buffptr = &gl->buffer[FT_GETL_BUFFSIZE];
	gl->buffer[0] = '\0';
	if (!(gl->flags & (FT_GETL_QUIET | FT_GETL_STDIN)))
		ft_printf("%s%s\"\n", "closed \"", gl->filepath);
}

static int		ft_getline_fill(t_getline *gl, char *endpos, t_buffer *buffer)
{
	size_t			len;

	if (buffer->size)
	{
		len = (endpos) ? (size_t)(endpos - gl->buffptr) :
			(FT_GETL_BUFFSIZE - 1) - (size_t)(gl->buffptr - gl->buffer);
		if (buffer->size <= len)
			len = buffer->size - 1;
		ft_memcpy(buffer->data, gl->buffptr, len);
		buffer->data[len] = '\0';
		buffer->data += len;
		buffer->size -= len;
	}
	else
		ft_printf("%s", "warning: buffer is full\n");
	if (endpos)
		gl->buffptr = endpos + 1;
	else
		return (0);
	return (1);
}

/*
** performs a new "read" event,
** if needed, will do a truncate of the remaining text at the end of the buffer
** to begining and append a \0 to the end of the string
*/

static int		ft_getline_load(t_getline *gl)
{
	ssize_t			readlen;
	const size_t	bsize = FT_GETL_BUFFSIZE - 1;

	readlen = 0;
	if (gl->buffptr == gl->buffer)
		gl->flags |= FT_GETL_TRUNC;
	else
		gl->buffptr = gl->buffer;
	readlen = read(gl->fd, gl->buffptr, bsize - (size_t)readlen);
	gl->reads += 1;
	if (readlen < 0)
		return (ft_getline_error(gl, FT_GETL_NONE, "read failed"));
	if (!readlen)
	{
		gl->flags |= FT_GETL_DONE;
		ft_getline_end(gl);
		return (-1);
	}
	gl->buffer[readlen] = '\0';
	gl->buffptr = gl->buffer;
	return (FT_GETL_OK);
}

ssize_t			ft_getline_read(t_getline *gl, t_buffer buffer)
{
	const size_t	usersize = buffer.size;
	int				retload;
	char			*endpos;

	gl->flags &= ~FT_GETL_TRUNC;
	if ((!(gl->flags & FT_GETL_OPEN)) || (gl->flags & FT_GETL_ERROR))
		return (-1);
	buffer.data[0] = '\0';
	endpos = NULL;
	while (endpos == NULL)
	{
		endpos = ft_strchr_old(gl->buffptr, '\n');
		if (ft_getline_fill(gl, endpos, &buffer))
			return ((ssize_t)(usersize - buffer.size));
		if ((retload = ft_getline_load(gl)))
			return (retload);
	}
	ft_printf("%s\n", "warning: grey code reached ");
	return (ft_getline_error(gl, FT_GETL_NONE, "dead end reached"));
}
