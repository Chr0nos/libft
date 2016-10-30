/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 15:04:59 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/30 19:17:28 by snicolet         ###   ########.fr       */
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
	while ((*str) && (!ft_strany(*str, FT_PF_CONVERTS)))
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

	va_start(ap, format);
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

	va_start(ap, format);
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
