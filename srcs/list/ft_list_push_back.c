/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:53:29 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/29 17:54:22 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **lst, void *data)
{
	t_list	*x;
	t_list	*last;

	x = ft_list_create_elem(data);
	if (x)
	{
		if (!*lst)
			*lst = x;
		else
		{
			last = *lst;
			while (last->next)
				last = last->next;
			last->next = x;
		}
	}
}


