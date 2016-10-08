/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 22:07:59 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/08 23:10:26 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
** this function is called if the padding requested is bigger than the buffer
** in this case we flush the buffer and do multiples writes (slow !)
** in "normal case" this should never append
*/

static inline int		ft_printf_padding_big(t_printf *pf, const char c, int n)
{
	const int		size = n;
	ssize_t			ret;

	if (pf->size)
		ft_printf_flush(pf);
	while ((n--) && ((ret = write(pf->fd, &c, 1)) > 0))
		pf->total_len += (size_t)ret;
	return (size);
}

/*
** this function append 'c' in an almost full buffer who cannot handle n char
** so we append for space_left char then flush then append the remaining chars
*/

static inline void		ft_printf_padding_partial(t_printf *pf, const char c,
	int n)
{
	n -= ft_printf_padding(pf, c, (int)pf->space_left);
	ft_printf_flush(pf);
	ft_printf_padding(pf, c, n);
}

/*
** this function append the character 'c' n times in the buffer
** if n is bigger than the buffer size ft_printf_padding_big will be called
** otherwise and if the space left is not big enoth to contain N caracters
** the function will copy 'space_left' chars, flush, and copy the remaining left
** return the N
*/

int						ft_printf_padding(t_printf *pf, const char c, int n)
{
	if (n <= 0)
		return (0);
	if (n > FT_PF_BSIZE)
		return (ft_printf_padding_big(pf, c, n));
	if ((size_t)n <= pf->space_left)
	{
		ft_memset(pf->buff_start, (int)c, (size_t)n);
		pf->buff_start += n;
		pf->size += (size_t)n;
		return (n);
	}
	ft_printf_padding_partial(pf, c, n);
	return (n);
}
