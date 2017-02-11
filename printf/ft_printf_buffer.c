/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 00:36:31 by snicolet          #+#    #+#             */
/*   Updated: 2017/02/11 10:23:28 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

/*
** this function is called in case of a full buffer BUT asprintf is runing
** in this case we realloc the memory area to be FT_PF_ASIZE higher
** space_left is also incremented to FT_PF_ASIZE to allow others appends
** total_len is incremented to pf->size
** if the realloc fail: we quit all the printf and set a error flag
** to be called this functions need flags FT_PF_NOWRITE and FT_PF_ALLOC
*/

void					ft_printf_flush_asprintf(t_printf *pf)
{
	pf->buff_asprintf = ft_realloc(pf->buff_asprintf,
		pf->size, pf->size + FT_PF_ASIZE);
	if (!pf->buff_asprintf)
	{
		pf->flags |= FT_PF_QUIT | FT_PF_ERROR;
		return ;
	}
	pf->buff_start = &pf->buff_asprintf[pf->size];
	pf->space_left += FT_PF_ASIZE;
	pf->total_len = pf->size;
}

/*
** flush the current buffer to the pf->fd file descriptor
** then reset the pf->buff_start pointer to the start, size to 0 and
** reset space_left to the total buffer size
** return 0 in case of normal mode, -1 if an exit is needed
*/

void					ft_printf_flush(t_printf *pf)
{
	ssize_t		size;

	if (pf->flags & FT_PF_NOWRITE)
	{
		if (pf->flags & FT_PF_ALLOC)
		{
			ft_printf_flush_asprintf(pf);
			return ;
		}
		pf->flags |= FT_PF_QUIT;
		pf->total_len = pf->size;
		return ;
	}
	size = write(pf->fd, pf->buffer, pf->size);
	if (size > 0)
		pf->total_len += (size_t)size;
	pf->buff_start = pf->buffer;
	pf->size = 0;
	pf->space_left = FT_PF_BSIZE;
}

/*
** called in case of len is supperior to the full buffer size
*/

static inline size_t	ft_printf_append_big(t_printf *pf, const char *data,
	size_t len)
{
	ssize_t				rsize;

	if (pf->size)
		ft_printf_flush(pf);
	rsize = write(pf->fd, data, len);
	if (rsize > 0)
		pf->total_len += (size_t)rsize;
	return (len);
}

/*
** copy the possible len in the buffer then ask for a quit to the main loop
** via FT_PF_QUIT
*/

static size_t			ft_printf_append_partialnowrite(t_printf *pf,
	const char *data, size_t len)
{
	const size_t	copied = pf->space_left;

	if (pf->flags & FT_PF_ALLOC)
	{
		ft_printf_flush_asprintf(pf);
		ft_printf_append(pf, data, len);
		return (len);
	}
	if (!copied)
		return (0);
	ft_memcpy(pf->buff_start, data, pf->space_left);
	pf->total_len += pf->space_left;
	pf->size += pf->space_left;
	pf->buff_start += pf->space_left;
	pf->space_left = 0;
	pf->flags |= FT_PF_QUIT;
	return (len);
}

/*
** return the lenght added to the buffer (basicly len)
** even in case of error len will be returned, the called has to check
** for flag FT_PF_QUIT in pf->flags
*/

size_t					ft_printf_append(t_printf *pf, const char *data,
	size_t len)
{
	const size_t		size = len;

	if (!len)
		return (0);
	if ((pf->flags & FT_PF_NOWRITE) && (len > pf->space_left))
		return (ft_printf_append_partialnowrite(pf, data, len));
	if (len > FT_PF_BSIZE)
		return (ft_printf_append_big(pf, data, len));
	if (len > pf->space_left)
	{
		ft_memcpy(pf->buff_start, data, pf->space_left);
		len -= pf->space_left;
		data += pf->space_left;
		pf->size = FT_PF_BSIZE;
		ft_printf_flush(pf);
		if (pf->flags & FT_PF_QUIT)
			return (len);
	}
	ft_memcpy(pf->buff_start, data, len);
	pf->size += len;
	pf->buff_start += len;
	pf->space_left -= len;
	return (size);
}
