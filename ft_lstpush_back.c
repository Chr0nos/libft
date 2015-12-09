/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:53:51 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/01 19:30:24 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpush_back(t_list **lst, t_list *item)
{
	if (!*lst)
		*lst = item;
	else
		ft_lstlast(*lst)->next = item;
	return (item);
}
