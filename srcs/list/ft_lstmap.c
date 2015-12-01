/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:50:04 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/01 19:19:29 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*x;
	t_list	*result;

	if (!lst)
		ft_crash();
	result = 0;
	x = lst;
	while (x)
	{
		ft_lstpush_back(&result, f(x));
		x = x->next;
	}
	return (result);
}
