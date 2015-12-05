/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 17:17:33 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/05 17:40:28 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstremove(t_list **item, t_list *parent, void (*f)())
{
	if (*item)
	{
		parent->next = (*item)->next;
		if (f)
			f((*item)->content);
		free(*item);
		*item = 0;
	}
}
