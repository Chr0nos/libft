/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 18:57:39 by snicolet          #+#    #+#             */
/*   Updated: 2015/09/10 23:38:47 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_H
# define BTREE_H

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

#endif
