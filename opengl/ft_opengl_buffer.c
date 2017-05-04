/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opengl_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 18:12:43 by snicolet          #+#    #+#             */
/*   Updated: 2017/05/04 18:58:38 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "opengl.h"

int			ft_opengl_buffer_load(GLuint *dest, GLuint type, const void *data,
	const size_t size)
{
	*dest = 0;
	glGenBuffers(1, dest);
	if (*dest == 0)
	{
		ft_putendl_fd("error: failed to create opengl buffer", 2);
		return (1);
	}
	glBindBuffer(type, *dest);
	glBufferData(type, (GLsizeiptr)size, data, GL_STATIC_DRAW);
	return (0);
}
