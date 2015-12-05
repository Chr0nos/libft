/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 13:20:11 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/05 17:41:40 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include "libft.h"
# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(const void *content, size_t content_size);
t_list				*ft_lstnewstr(char *str);
void				ft_lstremove(t_list **item, t_list *parent);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **ast, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstinsert(t_list **parent, t_list *item);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
size_t				ft_lststrlen(t_list *lst);
size_t				ft_lstsize(t_list *lst);
t_list				*ft_lstparent(t_list *lst, t_list *item);
void				ft_lstswap(t_list **lst, t_list *a, t_list *b);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstpush_back(t_list **lst, t_list *item);
t_list				*ft_lstpush_front(t_list **lst, t_list *item);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstsort(t_list **lst, int (*cmp)(t_list *, t_list *));
void				ft_lstpush_sort(t_list **lst, void *data, size_t size,
		int (*cmp)());

#endif
