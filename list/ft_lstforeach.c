/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstforeach.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 17:16:57 by snicolet          #+#    #+#             */
/*   Updated: 2018/02/13 07:19:50 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstforeach(t_list *lst, void *userdata,
	void (*f)(void *, size_t, void *))
{
	while (lst)
	{
		f(userdata, lst->content_size, lst->content);
		lst = lst->next;
	}
	return (userdata);
}
