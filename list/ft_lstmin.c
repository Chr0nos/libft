/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:29:12 by snicolet          #+#    #+#             */
/*   Updated: 2016/12/10 16:32:57 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmin(t_list *lst, int (*cmp)(t_list *, t_list *))
{
	t_list	*min;

	min = lst;
	lst = lst->next;
	while (lst)
	{
		if (cmp(min, lst) < 0)
			min = lst;
		lst = lst->next;
	}
	return (min);
}
