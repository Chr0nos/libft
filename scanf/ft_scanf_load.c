/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:59:23 by snicolet          #+#    #+#             */
/*   Updated: 2016/11/01 17:04:57 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** loads all modifiers into sf->flags then return the address in format
** where the function has stop his job
*/

const char			*ft_scanf_loadmods(const char *format, t_scanf *sf)
{
	const t_scanf_mod	*mod;
	int					p;

	p = FT_SF_MODS_COUNT;
	while (p--)
	{
		mod = &g_scanf_mods[p];
		if (!ft_strncmp(format, mod->str, mod->len))
		{
			sf->flags |= mod->flag;
			format += mod->len;
			if (!*format)
				return (format);
		}
	}
	return (format);
}
