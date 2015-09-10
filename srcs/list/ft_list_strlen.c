/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 11:57:48 by snicolet          #+#    #+#             */
/*   Updated: 2015/09/10 19:23:12 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "list.h"

int		ft_list_strlen(t_list *lst)
{
	int		len;

	len = 0;
	while (lst)
	{
		if (lst->data)
			len += ft_strlen((char*)(lst->data));
		lst = lst->next;
	}
	return (len);
}
