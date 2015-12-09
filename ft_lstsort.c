/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 19:45:02 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/01 19:51:58 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list **lst, int (*cmp)(t_list *, t_list *))
{
	t_list	*x;

	if (!*lst)
		return ;
	x = *lst;
	while (x->next)
	{
		if (cmp(x, x->next) > 0)
		{
			ft_lstswap(lst, x, x->next);
			x = *lst;
		}
		else
			x = x->next;
	}
}
