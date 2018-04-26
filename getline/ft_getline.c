/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 00:39:54 by snicolet          #+#    #+#             */
/*   Updated: 2018/04/27 00:06:20 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_getline.h"
#include <unistd.h>

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
	readlen = read(gl->fd, gl->buffptr, bsize - readlen);
	if (readlen < 0)
	{
		gl->flags |= FT_GETL_ERROR;
		return (-1);
	}
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
	gl->flags |= FT_GETL_ERROR;
	return (-1);
}
