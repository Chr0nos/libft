/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:48:33 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/01 17:54:29 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;

	if (*alst)
	{
		next = (*alst)->next;
		if (next)
			ft_lstdel(&next, del);
		del((*alst)->content, (*alst)->content_size);
		ft_memdel(alst);
	}
}
