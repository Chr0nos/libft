/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 22:51:22 by snicolet          #+#    #+#             */
/*   Updated: 2017/03/04 11:14:03 by snicolet         ###   ########.fr       */
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

void	ft_lstprintf_numeric(t_printf *pf)
{
	const t_list	*lst = (t_list*)pf->raw_value;
	char			buffer[20];
	int				len;

	pf->slen = 0;
	while (lst)
	{
		len = ft_itobuff(buffer, (int)(size_t)lst->content, 10, "0123456789");
		pf->slen += (int)ft_printf_append(pf, buffer, (size_t)len);
		lst = lst->next;
		if (lst)
			pf->slen += (int)ft_printf_append(pf, " ", 1);
	}
	pf->raw_len = pf->slen;
}
