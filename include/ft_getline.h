/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 23:59:42 by snicolet          #+#    #+#             */
/*   Updated: 2018/03/17 22:15:23 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETLINE_H
# define FT_GETLINE_H
# include <string.h>
# define FT_GETL_BUFFSIZE 4096
# define FT_GETL_OK		0
# define FT_GETL_NONE	0
# define FT_GETL_ERROR	(1u << 0)
# define FT_GETL_END	(1u << 1)
# define FT_GETL_OPEN	(1u << 2)
# define FT_GETL_FULL	(1u << 3)
# define FT_GETL_IOERR	(1u << 4)
# define FT_GETL_QUIET	(1u << 5)
# define FT_GETL_TRUNC	(1u << 6)
# define FT_GETL_OPENF	(1u << 7)
# define FT_GETL_NOTRUNC (1u << 8)
# define FT_GETL_DONE	(1u << 9)

/*
** this is my new multi purposes lines reader, a line cannot exeed
** FT_GETL_BUFFSIZE chars longs, after that flags error and full be set
** usage:
** ft_getline_init(&gl, FT_GETL_NONE);
** then while (ft_getline_sread(&gl, buffer, size) > 0)
** ----------------------------------------------------------------------------
** About the structure bellow:
** filepath : current file path
** buffer   : internal buffer used to store lines, don't link anything to it !
** buffpos  : write position in the buffer, this is where read will start to
**            insert ( &buffer[buffpos] will be used )
** fd       : the filepath file descriptor if the open has succeed
** flags    : binaries operators used, they can provite you some informations
**            about what happened like error type.
*/

typedef struct 			s_getline
{
	const char			*filepath;
	char				buffer[FT_GETL_BUFFSIZE];
	size_t				buffpos;
	int					fd;
	unsigned int		flags;
}						t_getline;

unsigned int			ft_getline_init(t_getline *gl, const char *filepath,
		const unsigned int flags);
int						ft_getline_read(t_getline *gl, char **line);
int						ft_getline_sread(t_getline *gl,
		char *buffer, size_t size);
int						ft_getline_error(t_getline *gl, unsigned int flags,
		const char *msg);
void					ft_getline_end(t_getline *gl);

#endif
