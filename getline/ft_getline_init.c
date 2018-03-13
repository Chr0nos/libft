/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 06:42:49 by snicolet          #+#    #+#             */
/*   Updated: 2018/03/13 06:46:31 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getline.h"
#include <unistd.h>
#include <fcntl.h>

unsigned int		ft_getline_init(t_getline *gl, const char *filepath,
		const unsigned int flags)
{
	gl->filepath = filepath;
	gl->buffpos = 0;
	gl->flags = (flags & FT_GETL_QUIET);
	gl->fd = open(filepath, O_RDONLY);
	if (gl->fd <= 0)
	{
		ft_getline_error(gl, FT_GETL_OPENF, "failed to open."); 
		return (gl->flags);
	}
	gl->flags |= FT_GETL_OPEN;
//	ft_getline_read(gl);
	return (FT_GETL_OK);
}
