/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstforeachi_suffix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 19:24:48 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/16 16:32:42 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static void	foreachi_suffix(t_list *lst, size_t p,
		void (*f)(size_t, size_t, void *))
{
	if (lst->next)
		foreachi_suffix(lst->next, p - 1, f);
	f(p, lst->content_size, lst->content);
}

void		ft_lstforeachi_suffix(t_list *lst,
		void (*f)(size_t, size_t, void *))
{
	foreachi_suffix(lst, ft_lstsize(lst) - 1, f);
}
