/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:22:32 by snicolet          #+#    #+#             */
/*   Updated: 2018/03/13 09:25:45 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getline.h"
#include <unistd.h>

void	ft_getline_end(t_getline *gl)
{
	if (gl->flags & FT_GETL_OPEN)
	{
		close(gl->fd);
		gl->fd = 0;
		gl->flags &= ~FT_GETL_OPEN;
	}
	gl->buffpos = 0;
	gl->buffer[0] = '\0';
}
