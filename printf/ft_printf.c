/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 15:04:59 by snicolet          #+#    #+#             */
/*   Updated: 2018/02/28 19:55:35 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

/*
** called on each sub chain delimited by %
** while the current character is not a conversion: we try to load a "config"
** config = (precision / min_width / modifier / flags)
** if a character is not a conversion and not a config: it's considerated as a
** conversion %c (and will be displayed with all already set config)
** see ft_printf_engine for details
*/

static inline const char	*ft_printf_exec(const char *str, t_printf *pf)
{
	size_t			seek;

	if (*str == '%')
	{
		ft_pf_conv_percent(pf);
		return (str + 1);
	}
	seek = 0;
	while ((*str) && (!ft_strchr(FT_PF_CONVERTS, *str)))
	{
		if (!(seek = ft_printf_loadall(pf, str)))
			break ;
		str += seek;
	}
	if (*str)
	{
		ft_printf_conv(pf, *str);
		return (str + 1);
	}
	return (str);
}

/*
** this function jump on each '%' char
** and send the position of the '%' + 1 pointer to ft_printf_exec
** if '%' is not in the format string anymore: the whole left string is append
** to the buffer
** all flags expet NOWRITE and FT_PF_QUIT are removed at each loop call
*/

void						ft_printf_engine(const char *fstr, t_printf *pf)
{
	const char		*c;
	const char		*sep = "%";
	int				len;

	while (((c = ft_strforf(fstr, sep, &len)) != NULL) &&
		(!(pf->flags & FT_PF_QUIT)))
	{
		pf->flags &= FT_PF_ALLOW;
		ft_printf_append(pf, fstr, (size_t)len);
		fstr = ft_printf_exec(c + 1, pf);
	}
	if (!(pf->flags & FT_PF_QUIT))
		ft_printf_append(pf, fstr, (size_t)len);
}

/*
** the same a ft_printf but take a file descriptor in parameter
** ex: ft_dprintf(2, "%s\n", "some error string");
*/

int							ft_dprintf(int fd, const char *format, ...)
{
	va_list		ap;
	t_printf	pf;
	char		buf[FT_PF_BSIZE];

	va_start(ap, format);
	pf.buffer = buf;
	ft_printf_init(&pf, &ap);
	pf.fd = fd;
	ft_printf_engine(format, &pf);
	va_end(ap);
	if (pf.size)
	{
		write(pf.fd, pf.buffer, pf.size);
		return (int)((pf.total_len + pf.size));
	}
	return ((int)pf.total_len);
}

int							ft_printf(const char *format, ...)
{
	va_list		ap;
	t_printf	pf;
	char		buf[FT_PF_BSIZE];

	va_start(ap, format);
	pf.buffer = buf;
	ft_printf_init(&pf, &ap);
	ft_printf_engine(format, &pf);
	va_end(ap);
	if (pf.size)
	{
		write(pf.fd, pf.buffer, pf.size);
		return ((int)(pf.total_len + pf.size));
	}
	return ((int)pf.total_len);
}

/*
** this if probably the most complicated function of this printf implementation
** this function's purpose is to be called INSIDE a previous call of printf,
** like ft_printf, ft_snprintf etc, in a normal case this is called inside a
** callback function of printf (%k or %K)
** this one make a new sub t_printf environement and re-run a ft_printf_engine
** then the revelant informations are sent to the original structure.
** the big idea here is to prevent a maximum of "write" syscalls, and prevent
** too many stack usage (each ft_printf call causes a FT_PF_BSIZE buf in the
** stack, this is not acceptable for many calls inside a callback function)
*/

int							ft_printf_stack(t_printf *pf,
		const char *format, ...)
{
	va_list				ap;
	t_printf			sub_pf;

	ft_bzero(&sub_pf, sizeof(t_printf));
	sub_pf.buffer = pf->buffer;
	sub_pf.buff_asprintf = pf->buff_asprintf;
	va_start(ap, format);
	ft_printf_init(&sub_pf, &ap);
	sub_pf.flags &= FT_PF_ALLOW;
	sub_pf.space_left = pf->space_left;
	sub_pf.buffer_maxsize = pf->buffer_maxsize;
	sub_pf.fd = pf->fd;
	ft_printf_engine(format, &sub_pf);
	va_end(ap);
	pf->buff_asprintf = sub_pf.buff_asprintf;
	pf->buff_start += sub_pf.total_len;
	pf->total_len += sub_pf.total_len;
	pf->slen += sub_pf.total_len;
	pf->space_left -= sub_pf.total_len;
	return ((int)sub_pf.total_len);
}
