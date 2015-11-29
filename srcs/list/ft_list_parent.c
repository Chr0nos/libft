/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_parent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:28:20 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/29 17:28:59 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_list_parent(t_list *item, t_list *root)
{
	if (!root)
		return (0);
	while (root->next)
	{
		if (root->next == item)
			return (root);
		root = root->next;
	}
	return (0);
}
