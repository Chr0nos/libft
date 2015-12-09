/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstparent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 19:39:46 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/01 19:40:45 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstparent(t_list *lst, t_list *item)
{
	while (lst)
	{
		if (item == lst->next)
			return (lst);
		lst = lst->next;
	}
	return (0);
}
