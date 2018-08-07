/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 06:48:32 by snicolet          #+#    #+#             */
/*   Updated: 2018/04/27 02:14:14 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_getline.h"
#include <unistd.h>

int					ft_getline_error(t_getline *gl, unsigned int flags,
		const char *msg)
{
	ft_getline_end(gl);
	gl->flags |= FT_GETL_ERROR | flags;
	if (!(gl->flags & FT_GETL_QUIET))
		ft_dprintf(STDERR_FILENO, "%s%s%s%s\n",
			"error: (", gl->filepath, "): ", msg);
	return (-1);
}
