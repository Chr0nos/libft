/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:43:10 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/15 16:47:26 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_lststrmap(t_list *lst)
{
	char	**tab;
	size_t	p;

	if (!(tab = (char**)malloc(sizeof(char*) * (ft_lstsize(lst) + 1))))
		return (NULL);
	p = 0;
	while (lst)
	{
		tab[p++] = (char *)lst->content;
		lst = lst->next;
	}
	tab[p] = NULL;
	return (tab);
}
