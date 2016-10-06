/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 00:36:31 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/06 15:23:07 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void					ft_printf_flush(t_printf *pf)
{
	const ssize_t	size = write(pf->fd, pf->buffer, pf->size);

	if (size > 0)
		pf->total_len += (size_t)size;
	pf->buff_start = pf->buffer;
	pf->size = 0;
	pf->space_left = FT_PRINTF_BSIZE;
}

void					ft_printf_append(t_printf *pf, const char *data,
	size_t len)
{
	ssize_t		rsize;

	if (!len)
		return ;
	pf->lastlen += len;
	if (len > FT_PRINTF_BSIZE)
	{
		ft_printf_flush(pf);
		rsize = write(pf->fd, data, len);
		if (rsize > 0)
			pf->total_len += (size_t)rsize;
		return ;
	}
	else if (len > pf->space_left)
	{
		ft_memcpy(pf->buff_start, data, pf->space_left);
		len -= pf->space_left;
		data += pf->space_left;
		pf->size = FT_PRINTF_BSIZE;
		ft_printf_flush(pf);
	}
	ft_memcpy(pf->buff_start, data, len);
	pf->size += len;
	pf->buff_start += len;
	pf->space_left -= len;
}

int					ft_printf_padding(t_printf *pf, const char c, int n)
{
	if (n <= 0)
		return (0);
	if ((size_t)n <= pf->space_left)
	{
		ft_memset(pf->buff_start, (int)c, (size_t)n);
		pf->buff_start += n;
		pf->size += (size_t)n;
		pf->lastlen += n;
		return (n);
	}
	while (n--)
		ft_printf_append(pf, &c, 1);
	return (n);
}
