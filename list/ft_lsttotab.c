/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttotab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 17:55:01 by snicolet          #+#    #+#             */
/*   Updated: 2018/02/14 11:35:42 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_lsttotab(t_list *lst)
{
	return (ft_lsttotab_size(lst, ft_lstsize(lst)));
}

void	**ft_lsttotab_size(t_list *lst, const size_t size)
{
	void			**tab;
	size_t			p;

	if (!size)
		return (NULL);
	tab = malloc(sizeof(void*) * (size + 1));
	if (!(tab))
		return (NULL);
	p = 0;
	while ((lst) && (p < size))
	{
		tab[p++] = lst->content;
		lst = lst->next;
	}
	tab[p] = NULL;
	return (tab);
}
