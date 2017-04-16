/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opengl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 11:49:59 by snicolet          #+#    #+#             */
/*   Updated: 2017/04/16 11:51:30 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPENGL
# define OPENGL
# include <GL/glew.h>

GLuint			ft_shader_compile(GLuint type, const char *file);

#endif
