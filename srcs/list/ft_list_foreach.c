/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 20:58:52 by snicolet          #+#    #+#             */
/*   Updated: 2015/09/19 23:17:12 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_list_foreach(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->data);
		lst = lst->next;
	}
}

void	ft_list_foreach_suffix(t_list *lst, void (*f)(void *))
{
	if (lst->next)
		ft_list_foreach_suffix(lst->next, f);
	f(lst->data);
}
