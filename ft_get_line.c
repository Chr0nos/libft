/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicoletr@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:15:20 by snicolet          #+#    #+#             */
/*   Updated: 2017/05/29 00:57:10 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static char		*gnl_buffer_append(t_gnlb *gnlb, char *rbuf, int *err)
{
	char		*tmp;

	if ((*err = (int)read(gnlb->fd, rbuf, GNL_BUFF_SIZE)) < 1)
		return (NULL);
	rbuf[*err] = '\0';
	gnlb->cursor = ft_strlen(gnlb->strb);
	if ((gnlb->cursor + (size_t)*err) >= gnlb->buf_size)
	{
		gnlb->buf_size += GNL_GROW_SIZE;
		tmp = (char *)malloc(sizeof(char) * gnlb->buf_size);
		if (tmp)
			ft_strcpy(ft_memset(tmp, 0, gnlb->buf_size), gnlb->strb);
		free(gnlb->strb);
		if (!(gnlb->strb = tmp))
			return (NULL);
	}
	tmp = gnlb->strb + gnlb->cursor;
	ft_strcpy(tmp, rbuf);
	return (tmp);
}

static void		*gnl_free(int const fd, t_list **gnlb_lst, t_gnlb *gnlb)
{
	t_list	*i;

	if (gnlb)
	{
		if (gnlb->strb)
			free(gnlb->strb);
		return (NULL);
	}
	i = *gnlb_lst;
	while (i && (*(int *)(i->content) != fd))
	{
		gnlb_lst = &(i->next);
		i = i->next;
	}
	if (!i)
		return (NULL);
	gnlb = (t_gnlb *)(i->content);
	if (gnlb->strb)
		free(gnlb->strb);
	free(i->content);
	*gnlb_lst = i->next;
	free(i);
	return (NULL);
}

static t_gnlb	*get_gnlb(int const fd, char *rbuf, t_list **gnlb_lst, int *err)
{
	t_list	*i;
	t_gnlb	ret;

	*err = -1;
	if (fd != 0 && fd < 3)
		return (NULL);
	i = *gnlb_lst;
	while (i && (*(int *)(i->content) != fd))
		i = i->next;
	if (i)
		return ((t_gnlb *)(i->content));
	*err = (int)read(fd, rbuf, GNL_BUFF_SIZE);
	if ((*err < 1))
		return (NULL);
	rbuf[*err] = '\0';
	ret = (t_gnlb){fd, 0, GNL_START_SIZE + 1, 0,
		malloc((sizeof(char) * (GNL_START_SIZE + 1)))};
	if (!(ret.strb) || !(i = ft_lstnew(&ret, sizeof(t_gnlb))))
		return (gnl_free(fd, gnlb_lst, &ret));
	ft_strncpy(ft_memset(ret.strb, 0, GNL_START_SIZE + 1), rbuf, (size_t)*err);
	ft_lstadd(gnlb_lst, i);
	return (i->content);
}

static int		valid_gnlb(t_list **gnlb_lst, t_gnlb *gnlb, char **line)
{
	if (line)
		*line = NULL;
	if (!gnlb)
		return (0);
	else if (!line)
		return ((int)(unsigned long)(gnl_free(gnlb->fd, gnlb_lst, NULL)));
	return (1);
}

int				ft_get_line(int const fd, char **line)
{
	static t_list	*gnlb_lst = NULL;
	char			rbuf[GNL_BUFF_SIZE + 1];
	char			*cur;
	t_gnlb			*gnlb;
	int				r;

	gnlb = get_gnlb(fd, rbuf, &gnlb_lst, &r);
	if (!valid_gnlb(&gnlb_lst, gnlb, line))
		return (r < 1 ? r : -1);
	cur = gnlb->strb;
	while (cur && !(cur = ft_strchr(cur, (int)'\n')))
		cur = gnl_buffer_append(gnlb, rbuf, &r);
	if (!gnlb->strb || (!cur && r == -1))
		return (-1);
	r = cur ? (int)(cur - gnlb->strb) : (int)ft_strlen(gnlb->strb);
	if (!(*line = (char *)malloc((unsigned)(r + 1))))
		return (-1);
	ft_strncpy(*line, gnlb->strb, (size_t)r)[r] = '\0';
	if (*(cur = (cur ? cur + 1 : gnlb->strb + r)))
		ft_memmove(gnlb->strb, cur, ft_strlen(cur) + 1);
	else
		gnl_free(fd, &gnlb_lst, NULL);
	return (1);
}
