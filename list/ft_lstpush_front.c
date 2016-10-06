/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 19:24:10 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/01 19:30:47 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpush_front(t_list **lst, t_list *item)
{
	item->next = *lst;
	*lst = item;
	return (item);
}
