/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 21:29:31 by snicolet          #+#    #+#             */
/*   Updated: 2015/09/27 12:00:05 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

void	ft_list_free(t_list *lst)
{
	t_list	*next;

	if (!lst)
		return ;
	if (lst->next)
	{
		next = lst->next;
		lst->next = 0;
		ft_list_free(next);
	}
	free(lst);
}
