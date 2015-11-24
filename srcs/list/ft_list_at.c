/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 15:29:12 by snicolet          #+#    #+#             */
/*   Updated: 2015/10/07 16:34:56 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list.h"

t_list		*ft_list_at(t_list *lst, t_size pos)
{
	t_size	p;

	p = 0;
	while ((p < pos) && (lst))
		lst = lst->next;
	if (p == pos)
		return (lst);
	return (0);
}
