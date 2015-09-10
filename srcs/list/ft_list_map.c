/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 11:07:08 by snicolet          #+#    #+#             */
/*   Updated: 2015/09/10 19:23:29 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

t_list	**ft_list_map(t_list *lst)
{
	t_list	**map;
	int		size;
	int		p;

	size = ft_list_size(lst);
	map = malloc(sizeof(t_list*) * size + 1);
	p = 0;
	while ((lst) && (p < size))
	{
		map[p] = lst;
		lst = lst->next;
		p++;
	}
	map[p] = 0;
	return (map);
}
