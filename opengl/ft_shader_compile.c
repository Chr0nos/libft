/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shader_compile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 11:31:43 by snicolet          #+#    #+#             */
/*   Updated: 2017/05/30 15:54:28 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GL/glew.h>
#include <stdlib.h>
#include "libft.h"
#include "opengl.h"

static int			ft_shader_cerror(GLuint shader)
{
	GLint		success;
	int			error_len;
	char		*error;

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &error_len);
	if (!error_len)
		return (0);
	if (!(error = malloc(sizeof(char) * ((unsigned)error_len + 1))))
		return (1);
	error[error_len] = '\0';
	glGetShaderInfoLog(shader, error_len, NULL, error);
	ft_dprintf(2, "opengl error: %s\n", error);
	free(error);
	return (2);
}

GLuint				ft_shader_compile(GLuint type, const char *file)
{
	GLuint			sh;
	char			*filecontent;

	if (!(filecontent = ft_readfile(file, NULL)))
	{
		ft_dprintf(2, "error: failed to open %s\n", file);
		return (0);
	}
	sh = glCreateShader(type);
	glShaderSource(sh, 1, (const GLchar *const *)(size_t)&filecontent, NULL);
	glCompileShader(sh);
	free(filecontent);
	if (ft_shader_cerror(sh))
		return (0);
	return (sh);
}
