/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 00:39:54 by snicolet          #+#    #+#             */
/*   Updated: 2018/03/13 06:22:16 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_getline.h"
#include <fcntl.h>
#include <unistd.h>

static int			getline_error(t_getline *gl, unsigned int flags,
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

static size_t		getline_read(t_getline *gl)
{
	size_t		spaceleft;
	ssize_t		readed;

	spaceleft = FT_GETL_BUFFSIZE - gl->buffpos;
	if (!spaceleft)
		return (getline_error(gl, FT_GETL_FULL, "no space left") + 1);
	readed = read(gl->fd, gl->buffer, spaceleft - 1);
	if (readed < 0)
		return (getline_error(gl,FT_GETL_IOERR, "input/output failure") + 1);
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

unsigned int		ft_getline_init(t_getline *gl, const char *filepath,
		const unsigned int flags)
{
	gl->filepath = filepath;
	gl->buffpos = 0;
	gl->flags = (flags & FT_GETL_QUIET);
	gl->fd = open(filepath, O_RDONLY);
	if (gl->fd <= 0)
	{
		getline_error(gl, FT_GETL_OPENF, "failed to open."); 
		return (gl->flags);
	}
	gl->flags |= FT_GETL_OPEN;
	getline_read(gl);
	return (FT_GETL_OK);
}

int					ft_getline_sread(t_getline *gl,
		char *buffer, size_t size)
{
	ssize_t		readed;
	char		*endpos;

	//ft_bzero(buffer, size);
	if ((!(gl->flags & FT_GETL_OPEN)) || (gl->flags & FT_GETL_ERROR))
		return (-1);
	if (gl->buffpos > 0)
	{
		endpos = strchr(gl->buffer, '\n');
		if (endpos)
		{
			readed = endpos - gl->buffer;
			if ((size_t)readed > size)
			{
				gl->flags |= FT_GETL_TRUNC;
				readed = size;
			}
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
