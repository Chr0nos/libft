/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 10:11:09 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/01 19:04:35 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

inline static void	add_pending(char *buffer, t_gnls *x)
{
	char	*tmp;

	if (*buffer == '\0')
		return ;
	else if (x->pb != NULL)
	{
		tmp = x->pb;
		x->pb = ft_strjoin(x->pb, buffer);
		ft_strdel(&tmp);
	}
	else
		x->pb = ft_strdup(buffer);
}

inline static void	rotate_pending(char **pending, size_t offset,
		size_t rest_len)
{
	char	*tmp;

	tmp = NULL;
	if (rest_len == 0)
		ft_strdel(pending);
	else
	{
		if (!(tmp = ft_strdup(*pending + offset)))
			return ;
		if (*pending != NULL)
			free(*pending);
	}
	*pending = tmp;
}

static int			ft_read_data(char *buffer, t_gnls *x, int buffer_len)
{
	int			read_lenght;
	size_t		rest_lenght;

	add_pending(buffer, x);
	if (x->pb == NULL)
		return (0);
	read_lenght = ft_strchrpos(x->pb, '\n');
	if (read_lenght < 0)
		read_lenght = (int)ft_strlen(x->pb);
	if ((buffer_len == GNL_BUFF_SIZE) && (buffer[buffer_len - 1] != '\n'))
		return (0);
	if (read_lenght >= 0)
	{
		rest_lenght = ft_strlen(x->pb) - (size_t)read_lenght;
		x->buffer = ft_strndup(x->pb, (size_t)read_lenght);
		x->buffer[read_lenght] = '\0';
		rotate_pending(&x->pb, (size_t)read_lenght + 1, rest_lenght);
		if (read_lenght > 0)
			return (1);
		return ((rest_lenght <= 0) ? 0 : 1);
	}
	return (0);
}

inline static int	ft_gnl_read(const int fd, t_gnls *x)
{
	char	buffer[GNL_BUFF_SIZE + 1];
	int		ret;
	int		ret_b;

	x->buffer = NULL;
	while ((ret = (int)read(fd, buffer, GNL_BUFF_SIZE)))
	{
		if (ret < 0)
			return (ret);
		buffer[ret] = '\0';
		ret_b = ft_read_data(buffer, x, ret);
		if (ret_b == 1)
			return (1);
	}
	buffer[0] = '\0';
	while ((ret_b = ft_read_data(buffer, x, 0)))
	{
		if (ret_b == 0)
			return (ret_b);
		else if (ret_b == 1)
			return (1);
	}
	return (0);
}

int					ft_get_next_line(int const fd, char **line)
{
	t_gnls			x;
	int				ret;
	static t_list	*lst_origin;
	t_list			*l;

	if ((fd < 0) || (!line))
		return (-1);
	l = lst_origin;
	while ((l) && (((t_gnls *)(l->content))->fd != fd))
		l = l->next;
	if ((!l) && (!(x.pb = NULL)))
	{
		if (!(l = ft_lstnew((void *)&x, sizeof(x))))
			return (-1);
		((t_gnls*)(l->content))->fd = fd;
		l = ft_lstadd(&lst_origin, l);
	}
	*line = 0;
	if ((ret = ft_gnl_read(fd, (t_gnls *)(l->content))) >= 0)
		*line = ((t_gnls *)(l->content))->buffer;
	if (ret == 0)
		ft_mfree(2, ((t_gnls*)l->content)->pb, ((t_gnls*)l->content)->buffer);
	if ((ret == 0) && (l != NULL))
		ft_lstremove(&l, &lst_origin, &free);
	return (ret);
}
