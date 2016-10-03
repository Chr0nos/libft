/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 14:16:37 by snicolet          #+#    #+#             */
/*   Updated: 2016/05/08 16:33:28 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *lst, void *(*f)(void*))
{
	t_list	*root;
	t_list	*item;

	root = NULL;
	item = NULL;
	while (lst)
	{
		if (!root)
		{
			item = ft_lstnewlink(f(lst->content), lst->content_size);
			root = item;
		}
		else
		{
			item->next = ft_lstnewlink(f(lst->content), lst->content_size);
			item = item->next;
		}
		lst = lst->next;
	}
	return (root);
}
