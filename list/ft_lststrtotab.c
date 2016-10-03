/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrtotab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 15:30:38 by snicolet          #+#    #+#             */
/*   Updated: 2016/05/14 15:35:44 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_lststrtotab(t_list *lst)
{
	size_t	pos;
	char	**tab;

	if (!(tab = malloc(sizeof(char*) * (ft_lstsize(lst) + 1))))
		return (NULL);
	pos = 0;
	while (lst)
	{
		tab[pos++] = (char*)lst->content;
		lst = lst->next;
	}
	tab[pos] = NULL;
	return (tab);
}
