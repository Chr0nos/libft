/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opengl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 11:49:59 by snicolet          #+#    #+#             */
/*   Updated: 2017/05/30 15:52:57 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPENGL_H
# define OPENGL_H
# include <GL/glew.h>

GLuint			ft_shader_compile(GLuint type, const char *file);
int				ft_opengl_buffer_load(GLuint *dest, GLuint type,
	const void *data, const size_t size);

#endif
