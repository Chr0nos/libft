/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 22:00:08 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/01 22:04:26 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lststrlen(t_list *lst)
{
	size_t	size;

	size = 0;
	while (lst)
	{
		size += ft_strlen((char*)lst->content);
		lst = lst->next;
	}
	return (size);
}
