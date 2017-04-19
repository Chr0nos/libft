/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstforeach_suffix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 17:32:31 by snicolet          #+#    #+#             */
/*   Updated: 2017/04/19 20:25:32 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstforeach_suffix(t_list *lst, void (*f)(void *))
{
	if (lst)
	{
		if (lst->next)
			ft_lstforeach_suffix(lst->next, f);
		f(lst->content);
	}
}
