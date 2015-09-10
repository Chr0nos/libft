/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 21:29:31 by snicolet          #+#    #+#             */
/*   Updated: 2015/09/10 19:22:22 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

void	ft_list_free(t_list *lst)
{
	if (!lst)
		return ;
	if (lst->next)
		ft_list_free(lst->next);
	free(lst);
}
