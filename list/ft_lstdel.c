/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:48:33 by snicolet          #+#    #+#             */
/*   Updated: 2016/05/08 18:12:44 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst)
	{
		if ((*alst)->next)
			ft_lstdel(&(*alst)->next, del);
		if (del)
			del((*alst)->content, (*alst)->content_size);
		ft_memdel((void**)alst);
	}
}