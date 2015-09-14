/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/14 15:29:45 by snicolet          #+#    #+#             */
/*   Updated: 2015/09/14 15:35:34 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*ft_list_search(t_list *lst, void *dataref, int (*cmp)(void *, void *))
{
	while (lst)
	{
		if ((*cmp)(lst->data, dataref) == 0)
			return (lst);
		lst = lst->next;
	}
	return (0);
}
