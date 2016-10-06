/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewlink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 23:27:20 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/07 23:30:50 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

t_list	*ft_lstnewlink(void *content, size_t content_size)
{
	t_list	*x;

	if (!(x = malloc(sizeof(t_list))))
		return (NULL);
	x->content = content;
	x->content_size = content_size;
	x->next = NULL;
	return (x);
}
