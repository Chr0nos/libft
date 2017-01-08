/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstissort_circular.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 20:15:26 by snicolet          #+#    #+#             */
/*   Updated: 2017/01/08 20:21:31 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstissort_circular(t_list *lst, int (*cmp)(t_list *, t_list *))
{
	const t_list	*lower = lst;

	if (!lst)
		return (1);
	while (lst->next)
	{
		if ((cmp(lst, lst->next) > 0) && (cmp(ft_lstlast(lst), lst)) > 0)
		{
			return (0);
		}
		lst = lst->next;
	}
	return (1);
}
