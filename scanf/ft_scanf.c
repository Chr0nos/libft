/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 19:15:33 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/30 19:44:29 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_scanf.h"

static inline const char	*ft_scanf_exec(const char *s, t_scanf *sf)
{
	(void)sf;
	return (s + 1);
}

/*
** this function jump between each % checking for validity of format
*/

static int					ft_scanf_engine(const char *s, const char *format,
	t_scanf *sf)
{
	const char		*c;
	const char		*sep = "%";
	int				len;

	while (((c = ft_strforf(s, sep, &len)) != NULL) &&
		(!(sf->flags & (FT_SF_QUIT | FT_SF_ERROR))))
	{
		if (ft_strncmp(s, format, (size_t)len))
			return (FT_SF_QUIT | FT_SF_ERROR);
		format += len;
		s = ft_scanf_exec(c + 1, sf);
	}
	return (0);
}

int							ft_sscanf(const char *s, const char *format, ...)
{
	va_list		ap;
	t_scanf		sf;

	sf.total_len = 0;
	sf.flags = 0;
	sf.ap = &ap;
	va_start(ap, format);
	ft_scanf_engine(s, format, &sf);
	va_end(ap);
	return (0);
}
