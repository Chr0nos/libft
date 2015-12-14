/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstforeach_suffix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 17:32:31 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/14 19:16:03 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstforeach_suffix(t_list *lst, void (*f)())
{
	if (lst)
	{
		if (lst->next)
			ft_lstforeach_suffix(lst->next, f);
		f(lst->content);
	}
}
