/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 19:56:32 by snicolet          #+#    #+#             */
/*   Updated: 2015/09/10 19:22:04 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*ft_list_push_back(t_list *lst, void *data)
{
	t_list	*x;
	t_list	*last;

	x = ft_list_create_elem(data);
	if (!lst)
		return (x);
	last = ft_list_last(lst);
	if (last)
		last->next = x;
	return (lst);
}

t_list	*ft_list_push_front(t_list *lst, void *data)
{
	t_list	*x;

	x = ft_list_create_elem(data);
	x->next = lst;
	return (x);
}
