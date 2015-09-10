/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 13:20:11 by snicolet          #+#    #+#             */
/*   Updated: 2015/09/10 16:38:22 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include "ft.h"

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

int					ft_list_size(t_list *lst);
t_list				*ft_list_last(t_list *item);
t_list				*ft_list_parent(t_list *item, t_list *root);
t_list				*ft_list_create_elem(void *data);
t_list				*ft_list_last(t_list *item);
t_list				*ft_list_sort(t_list *lst, int (*cmp)());
t_list				*ft_list_push_back(t_list *lst, void *data);
t_list				*ft_list_push_front(t_list *lst, void *data);
t_list				**ft_list_map(t_list *lst);
t_list				*ft_list_swap(t_list *a, t_list *b, t_list *root);
t_list				*ft_list_remove(t_list *lst, t_list *item);
void				ft_list_insert(t_list *parent, t_list *item);
void				ft_list_foreach(t_list *lst, void (*f)(void *));
void				ft_list_free(t_list *lst);
int					ft_list_strlen(t_list *lst);
char				*ft_list_to_char(t_list *lst, char c);

#endif
