/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:48:00 by edelangh          #+#    #+#             */
/*   Updated: 2016/09/12 10:56:13 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static t_fd_list	*get_buf(int const fd)
{
	static t_fd_list	*lst = NULL;
	t_fd_list			*tmp;
	t_fd_list			*tmp2;

	tmp = lst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = (t_fd_list*)ft_memalloc(sizeof(t_fd_list));
	if (!tmp)
		return (NULL);
	if (!(tmp->buffer = (char*)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (NULL);
	tmp->next = NULL;
	tmp->fd = fd;
	if (!lst)
		return ((lst = tmp));
	tmp2 = lst;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	return (tmp);
}

static void			ft_resize_buff(char **buffer, int n)
{
	int	i;

	i = 0;
	while (i < BUFF_SIZE)
	{
		if (i + n < BUFF_SIZE)
			(*buffer)[i] = (*buffer)[i + n + 1];
		else
			(*buffer)[i] = '\0';
		++i;
	}
}

static int			ft_addbuffer(char **line, char **buffer, int n, int fd)
{
	int		lline;
	char	*tmp;
	int		n_save;

	n_save = n;
	lline = get_buf(fd)->lline;
	tmp = *line;
	(*line) = (char*)ft_memalloc(sizeof(char) * (unsigned int)(lline + n + 1));
	get_buf(fd)->lline = lline + n;
	if (!*line)
		return (-1);
	lline = -1;
	while (++lline > -1 && tmp && tmp[lline])
		(*line)[lline] = tmp[lline];
	free(tmp);
	while (n--)
		(*line)[lline + n] = (*buffer)[n];
	ft_resize_buff(buffer, n_save);
	return (0);
}

static int			ft_check_error(int fd, char ***buf, char **line, int *f)
{
	if (fd < 0)
		return (-1);
	if (!get_buf(fd))
		return (-1);
	if (!(*buf = &(get_buf(fd)->buffer)) || !BUFF_SIZE || !line)
		return (-1);
	get_buf(fd)->lline = 0;
	*line = NULL;
	*f = 1;
	return (0);
}

int					ft_get_next_line(int const fd, char **line)
{
	char				**buf;
	int					len;
	int					f;

	if (ft_check_error(fd, &buf, line, &f))
		return (-1);
	while (f != -1)
	{
		if (!(*buf)[0] && (len = (int)read(fd, *buf, BUFF_SIZE)) != BUFF_SIZE)
		{
			if (len == -1)
				return (-1);
			f = (ft_strchr(*buf, '\n') != NULL);
			len = (int)ft_strsublen(*buf, '\n');
			f = (ft_addbuffer(line, buf, len, fd) == -1 ? -1 : f);
			return ((f == -1 ? -1 : f || ft_strlen(*buf) || ft_strlen(*line)));
		}
		if ((len = (int)ft_strsublen(*buf, '\n')) != -2 && (*buf)[len] == '\0')
			f = ft_addbuffer(line, buf, len, fd);
		else if ((*buf)[len] == '\n')
			return (1 + (f = ft_addbuffer(line, buf, len, fd)));
	}
	return (-1);
}
