/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 13:21:17 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/23 13:34:50 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <fcntl.h>

/*
** thoses conversions are not included in the ft_printf functions
** you have to use them as a kernel (%lk)
*/

void	ft_printf_conv_fd(t_printf *pf)
{
	const int		fd = (int)pf->raw_value;
	ssize_t			len;
	char			buffer[1024];

	while ((len = read(fd, buffer, 1024)) > 0)
		pf->slen += (int)ft_printf_append(pf, buffer, (size_t)len);
	pf->raw_len = pf->slen;
}

void	ft_printf_conv_file(t_printf *pf)
{
	const char		*filepath = (const char*)pf->raw_value;
	int				fd;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		ft_printf_append(pf, "unable to open file", 19);
		return ;
	}
	pf->raw_value = (intmax_t)fd;
	ft_printf_conv_fd(pf);
	close(fd);
}
