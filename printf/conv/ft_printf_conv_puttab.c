/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_puttab.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:52:43 by snicolet          #+#    #+#             */
/*   Updated: 2017/06/05 15:32:38 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** put a tab at the format of argv to printf
** ex: ft_printf(%lk, &ft_printf_puttab, av, ac)
** warning: this need an extra va_arg : the size of the tab
*/

void		ft_printf_conv_puttab(t_printf *pf)
{
	char	**tab;
	int		p;
	size_t	len;
	int		ac;

	ac = va_arg(*pf->ap, int);
	pf->raw_len = 0;
	p = 0;
	tab = (char**)(size_t)pf->raw_value;
	while (p < ac)
	{
		len = ft_strlen(tab[p]);
		ft_printf_append(pf, tab[p], len);
		ft_printf_append(pf, "\n", 1);
		p++;
		pf->raw_len += len + 1;
	}
	pf->slen = pf->raw_len;
}
