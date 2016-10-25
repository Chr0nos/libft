/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttotab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 17:55:01 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/25 17:59:13 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_lsttotab(t_list *lst)
{
	const size_t	size = ft_lstsize(lst);
	void			**tab;
	size_t			p;

	tab = malloc(sizeof(void*) * (size + 1));
	if (!(tab))
		return (NULL);
	p = 0;
	while (lst)
	{
		tab[p++] = lst->content;
		lst = lst->next;
	}
	tab[p] = NULL;
	return (tab);
}
