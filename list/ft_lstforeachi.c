/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstforeachi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 19:12:26 by snicolet          #+#    #+#             */
/*   Updated: 2018/02/13 07:20:16 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_lstforeachi(t_list *lst, void *userdata,
	void (*f)(size_t, void *, size_t, void *))
{
	size_t			p;

	p = 0;
	while (lst)
	{
		f(p++, userdata, lst->content_size, lst->content);
		lst = lst->next;
	}
	return (userdata);
}
