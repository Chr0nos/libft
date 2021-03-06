/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttotab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 17:55:01 by snicolet          #+#    #+#             */
/*   Updated: 2018/10/20 15:16:45 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		**ft_lsttotab(t_list *lst)
{
	return (ft_lsttotab_size(lst, ft_lstsize(lst)));
}

void		**ft_lsttotab_size(t_list *lst, const size_t size)
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

/*
** takes all lst->content items and put it into a tab, if the list is too small
** then the missing filds will be set to NULL
*/

void		ft_lsttotab_load(t_list *lst, void **tab, size_t n)
{
	size_t		i;

	i = 0;
	while ((lst) && (i < n))
	{
		tab[i++] = lst->content;
		lst = lst->next;
	}
	while (i < n)
		tab[i++] = NULL;
}

void		ft_lsttotab_loadrev(t_list *lst, void **tab, size_t n)
{
	size_t			i;

	if (!n)
		return ;
	i = ft_lstsize(lst);
	if (i > n)
		i = n - 1;
	tab[i] = NULL;
	while (i--)
	{
		tab[i] = lst->content;
		lst = lst->next;
	}
}
