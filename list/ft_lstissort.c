/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstissort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 00:08:15 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/13 00:23:00 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstissort(t_list *lst, int (*cmp)(t_list *, t_list *))
{
	if (!lst)
		return (1);
	while (lst->next)
	{
		if (cmp(lst, lst->next) > 0)
			return (0);
		lst = lst->next;
	}
	return (1);
}
