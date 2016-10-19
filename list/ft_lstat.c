/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 07:23:23 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/19 07:25:58 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** return the item at positon "p" in the list
** if the positon is not in the list NULL is retuned
*/

t_list	*ft_lstat(t_list *lst, int p)
{
	while (lst)
	{
		if (!p--)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
