/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftobuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 14:48:05 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/09 17:19:04 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define FT_F_SIGN(x, bits) (bits & 0x80000000)
#define FT_F_EXP(x, bits) ((bits & 0x7F800000) >> 22)
#define FT_F_FRACTION(x, bits) (bits & 0x7FFFFF)

/*
** float binary representation:
** [sign] [exposant] [fraction]
** 1bit	   8bits     23bits
** -
** the exposant has 1 bit of sign [sign][value]
** full representation
**          [0    000000000   00000000000000000000000]
**          [s    s00000000   00000000000000000000000]
** masks:       [0x7f800000]  [      0x7fffff        ]
** -
** examples: [S]   [E]         [F]
** 42.0 =    [0]   [10000100]  [01010000000000000000000]
**                 (4)
*/

int		ft_ftobuff(char *buffer, float nb, unsigned int precision)
{
	char					*c;
	const unsigned int		bits = *(unsigned int*)&nb;

	c = buffer;
	(void)c;
	(void)FT_F_SIGN(1, bits);
	(void)FT_F_EXP(1, bits);
	(void)FT_F_FRACTION(1, bits);
	(void)precision;
	return (0);
}

/*
int		ft_ftobuff(char *buffer, double nb, unsigned int base, const char *map)
{
	int				real;
	int				real_len;
	unsigned int	digit;
	unsigned int	x;

	if ((nb < 0.0) && (nb > -1.0))
	{
		buffer[0] = '-';
		buffer++;
	}
	real = (int)nb;
	real_len = ft_itobuff(buffer, real, base, map);
	buffer[real_len++] = '.';
	digit = 0;
	while (digit < 12)
	{
		x = (unsigned int)(((nb < 0) ? -nb : nb) * (double)(base * digit));
		buffer[real_len++] = map[x % base];
		digit++;
	}
	buffer[real_len++] = '\0';
	return (real_len);
}
*/
