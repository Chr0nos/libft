/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstforeachi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 19:12:26 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/15 19:24:37 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_lstforeachi(t_list *lst, void (*f)(size_t, size_t, void *))
{
	size_t	p;

	p = 0;
	while (lst)
	{
		f(p++, lst->content_size, lst->content);
		lst = lst->next;
	}
}
