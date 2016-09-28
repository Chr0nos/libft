/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:53:23 by snicolet          #+#    #+#             */
/*   Updated: 2016/09/28 20:39:46 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdarg.h>
# define FT_PRINTF_BSIZE		2048
# define FT_PRINTF_CONVERTS		"sSpdDioOuUxXcC"
# define FT_PRINTF_FLAGS		"#0-+ "
# define FT_PRINTF_MODIFIERS	"#hlL"

/*
** ft_printf flags
*/

# define FT_PRINTF_FLAGSNUM		5
# define FT_PRINTF_CONVS		13

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
# define FT_PRINTF_PREC			(1u << 11)
# define FT_PRINTF_CONV_STR		(1u << 12)
# define FT_PRINTF_CONV_INT		(1u << 13)
# define FT_PRINTF_CONV_UINT	(1u << 14)

struct s_printf;

typedef struct		s_printf_convert
{
	int				letter;
	int				padding;
	void			(*convert)(struct s_printf *);
}					t_printf_convert;

typedef struct		s_printf
{
	va_list				*ap;
	char				buffer[FT_PRINTF_BSIZE];
	char				*buff_start;
	unsigned int		flags;
	int					precision;
	int					fd;
	int					padding;
	size_t				total_len;
	size_t				size;
	size_t				space_left;
}					t_printf;

typedef struct		s_printf_cfg
{
	int				letter;
	unsigned int	flag;
	unsigned int	mask;
	int				padding;
}					t_printf_cfg;

void				ft_printf_convert_int(t_printf *pf);
void				ft_printf_convert_str(t_printf *pf);

static const t_printf_convert g_printf_convs[FT_PRINTF_CONVS] = {
	(t_printf_convert){'d', 0, &ft_printf_convert_int},
	(t_printf_convert){'s', 0, &ft_printf_convert_str}
};

static const t_printf_cfg g_printf_cfg[FT_PRINTF_FLAGSNUM] = {
	(t_printf_cfg){'#', FT_PRINTF_FLAG_DIESE, 0, 0},
	(t_printf_cfg){'0', FT_PRINTF_FLAG_ZERO, 0, 0},
	(t_printf_cfg){'-', FT_PRINTF_FLAG_LESS, 0, FT_PRINTF_FLAG_MORE},
	(t_printf_cfg){'+', FT_PRINTF_FLAG_MORE, 0, FT_PRINTF_FLAG_LESS},
	(t_printf_cfg){' ', FT_PRINTF_FLAG_SPACE, 0, 0}
};

#endif
