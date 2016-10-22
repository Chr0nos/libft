/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 22:51:22 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/22 22:56:00 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprintf(t_printf *pf)
{
	const t_list	*lst = (t_list *)pf->raw_value;

	pf->slen = 0;
	while (lst)
	{
		pf->slen += (int)ft_printf_append(pf, lst->content,
			(lst->content_size > 0) ? lst->content_size :
			ft_strlen(lst->content));
		lst = lst->next;
		if (lst)
			pf->slen += (int)ft_printf_append(pf, " ", 1);
	}
	pf->raw_len = pf->slen;
}
