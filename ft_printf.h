/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:53:23 by snicolet          #+#    #+#             */
/*   Updated: 2016/09/15 20:52:12 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# define FT_PRINTF_BSIZE		2048
# define FT_PRINTF_CONVERTS		"sSpdDioOuUxXcC"

/*
** ft_printf flags
*/

# define FT_PRINTF_FLAGS		5

# define FT_PRINTF_FLAG_DIESE	(1u << 0)
# define FT_PRINTF_FLAG_ZERO	(1u << 1)
# define FT_PRINTF_FLAG_LESS	(1u << 2)
# define FT_PRINTF_FLAG_MORE	(1u << 3)
# define FT_PRINTF_FLAG_SPACE	(1u << 4)
# define FT_PRINTF_FLAG_H		(1u << 5)
# define FT_PRINTF_FLAG_HH		(1u << 6)
# define FT_PRINTF_FLAG_L		(1u << 7)
# define FT_PRINTF_FLAG_LL		(1u << 8)
# define FT_PRINTF_FLAG_J		(1u << 9)
# define FT_PRINTF_FLAG_Z		(1u << 10)

typedef struct		s_printf
{
	char			buffer[FT_PRINTF_BSIZE];
	int				bpos;
	unsigned int	flags;
	unsigned int	precision;
}					t_printf;

typedef struct		s_printf_cfg
{
	int				letter;
	unsigned int	flag;
	unsigned int	mask;
	int				padding;
}					t_printf_cfg;

static const t_printf_cfg	g_printf_cfg[FT_PRINTF_FLAGS] = {
	(t_printf_cfg){'#', FT_PRINTF_FLAG_DIESE, 0, 0},
	(t_printf_cfg){'0', FT_PRINTF_FLAG_ZERO, 0, 0},
	(t_printf_cfg){'-', FT_PRINTF_FLAG_LESS, 0, 0},
	(t_printf_cfg){'+', FT_PRINTF_FLAG_MORE, 0, 0},
	(t_printf_cfg){' ', FT_PRINTF_FLAG_SPACE, 0, 0}
};

#endif
