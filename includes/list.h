/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 13:20:11 by snicolet          #+#    #+#             */
/*   Updated: 2015/10/31 22:54:13 by snicolet         ###   ########.fr       */
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
t_list				*ft_list_at(t_list *lst, t_size pos);
t_list				*ft_list_push_params(int ac, char **av);
void				ft_list_sort(t_list **lst, int (*cmp)());
void				ft_list_push_back(t_list **lst, void *data);
void				ft_list_push_front(t_list **lst, void *data);
void				ft_list_push_sort(t_list **lst, void *data,
					int (*cmp)(void *, void *));
t_list				**ft_list_map(t_list *lst);
void				ft_list_swap(t_list *a, t_list *b, t_list **root);
t_list				*ft_list_remove(t_list *lst, t_list *item);
void				ft_list_insert(t_list **parent, t_list *item);
int					ft_list_insert_at(t_list *lst, void *val, unsigned int pos);
void				ft_list_foreach(t_list *lst, void (*f)(void *));
void				ft_list_foreach_suffix(t_list *lst, void (*f)(void *));
void				ft_list_free(t_list **lst);
int					ft_list_strlen(t_list *lst);
char				*ft_list_to_char(t_list *lst, char c);
t_list				*ft_list_search(t_list *lst, void *dataref,
						int (*cmp)(void *, void *));
#endif
