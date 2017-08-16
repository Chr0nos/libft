/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 10:46:53 by snicolet          #+#    #+#             */
/*   Updated: 2017/08/16 10:47:17 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** search for item in the list, based on the cmp comparaison
** returns the first matched item, NULL if item is not found
*/

t_list		*ft_lstsearch(t_list *lst, t_list *item,
	int (*cmp)(t_list *, t_list *))
{
	while (lst)
	{
		if (cmp(lst, item) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
