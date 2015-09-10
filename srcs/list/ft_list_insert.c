/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 00:02:52 by snicolet          #+#    #+#             */
/*   Updated: 2015/09/10 19:22:28 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_list_insert(t_list *parent, t_list *item)
{
	t_list	*tmp;

	tmp = parent->next;
	parent->next = item;
	item->next = tmp;
}
