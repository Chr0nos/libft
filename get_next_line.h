/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 14:15:48 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/28 16:17:04 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# define GNL_BUFF_SIZE 999
# include <string.h>

typedef struct	s_gnlstatic_of_doom
{
	int			fd;
	int			memory_padding;
	char		*buffer;
	char		*pb;
}				t_gnls;

int				ft_get_next_line(int const fd, char **line);

#endif
