/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:00:04 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/01 18:11:02 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert(t_list **parent, t_list *item)
{
	if (!*parent)
		*parent = item;
	else
	{
		item->next = *parent;
		(*parent)->next = item;
	}
}
