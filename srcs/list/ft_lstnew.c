/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:11:01 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/01 18:25:28 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

t_list		*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*x;

	if (!(x = malloc(sizeof(t_list))))
		return (NULL);
	x->content = ((content) ? ft_memdup(content, content_size) : NULL);
	x->content_size = content_size;
	x->next = NULL;
	return (x);
}