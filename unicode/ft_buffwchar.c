/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffwchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:10:46 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/04 23:22:49 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_numbits(unsigned int nb)
{
	int		len;

	len = 1;
	while ((nb = nb >> 1))
		len++;
	return (len);
}

int				ft_buffwchar(const wchar_t c, char *buff)
{
	int					len;
	const unsigned int	ch = (unsigned int)c;
	const int			n = ft_numbits(ch);

	len = 0;
	if ((n > 7) && (++len))
	{
		if ((n > 11) && (++len))
		{
			if ((n > 16) && (len += 2))
			{
				*(buff++) = (char)(((ch >> 18) & 7) | 240);
				*(buff++) = (char)(((ch >> 12) & 63) | 128);
			}
			else if (++len)
				*(buff++) = (char)(((ch >> 12) & 15) | 224);
			*(buff++) = (char)(((ch >> 6) & 63) | 128);
		}
		else if (++len)
			*(buff++) = (char)(((ch >> 6) & 31) | 192);
		*(buff++) = (char)((ch & 63) | 128);
	}
	else if (++len)
		*(buff++) = (char)ch;
	return (len);
}
