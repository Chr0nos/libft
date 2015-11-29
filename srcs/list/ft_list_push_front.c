/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:54:34 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/29 17:54:50 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_front(t_list **lst, void *data)
{
	t_list	*x;

	if (!lst)
		return ;
	x = ft_list_create_elem(data);
	if (!x)
		return ;
	x->next = *lst;
	*lst = x;
}

