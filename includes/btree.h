/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 18:57:39 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/29 17:51:25 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_H
# define BTREE_H
# include "libft.h"
# include "string.h"

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*data;
}					t_btree;

void				ft_btree_foreach_infix(t_btree *root, void (*f)(void *));
void				ft_btree_foreach_prefix(t_btree *root, void (*f)(void *));
void				ft_btree_foreach_suffix(t_btree *root, void (*f)(void *));
t_btree				*ft_btree_create_node(void *data);
void				ft_btree_add(t_btree **root, void *data, int (*f)());
t_btree				*ft_btree_search_mess(t_btree *root, void *val, int (*f)());
t_btree				*ft_btree_search(t_btree *root, void *data, int (*f)());
t_btree				*ft_btree_parent(t_btree *root, t_btree *item);
void				ft_btree_insert(t_btree **node, void *data, int (*f)());
int					ft_btree_level(t_btree *root, t_btree *item, int level);
size_t				ft_btree_level_max(t_btree *root);

#endif
