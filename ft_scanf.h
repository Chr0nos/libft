/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 19:20:46 by snicolet          #+#    #+#             */
/*   Updated: 2016/11/02 00:22:30 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCANF
# define FT_SCANF

# define FT_SF_CONVERTS	"dsf"

# define FT_SF_QUIT			(1u << 0)
# define FT_SF_ERROR		(1u << 1)
# define FT_SF_MOD_HH		(1u << 2)
# define FT_SF_MOD_H		(1u << 3)
# define FT_SF_MOD_L		(1u << 4)
# define FT_SF_MOD_LL		(1u << 5)
# define FT_SF_FLAG_SKIP	(1u << 6)
# define FT_SF_FLAG_PREC	(1u << 7)

typedef struct		s_scanf
{
	va_list			*ap;
	const char		*str;
	int				total_len;
	unsigned int	flags;
	int				precision;
	unsigned int	min_width;
}					t_scanf;


int					ft_sscanf(const char *s, const char *format, ...);
const char			*ft_scanf_loadmods(const char *format, t_scanf *sf);

/*
** setters functions, they are all used as functions pointer
** in ft_scanf_exec (static)
*/

int					ft_scanf_set_int(t_scanf *sf);
int					ft_scanf_set_str(t_scanf *sf);
int					ft_scanf_set_float(t_scanf *sf);

typedef struct		s_scanf_set
{
	int				letter;
	int				flags;
	int				(*set)(t_scanf *sf);
}					t_scanf_set;

# define FT_SF_CONVCOUNT 3

static const t_scanf_set g_scanf_set[FT_SF_CONVCOUNT] = {
	(t_scanf_set){'d', 0, ft_scanf_set_int},
	(t_scanf_set){'s', 0, ft_scanf_set_str},
	(t_scanf_set){'f', 0, ft_scanf_set_float}
};

/*
** modifiers
*/

typedef struct		s_scanf_mod
{
	unsigned int	flag;
	unsigned int	len;
	const char		*str;
}					t_scanf_mod;

# define FT_SF_MODS_COUNT 5

static const t_scanf_mod g_scanf_mods[FT_SF_MODS_COUNT] = {
	(t_scanf_mod){FT_SF_MOD_HH, 2, "hh"},
	(t_scanf_mod){FT_SF_MOD_H, 1, "h"},
	(t_scanf_mod){FT_SF_MOD_L, 1, "l"},
	(t_scanf_mod){FT_SF_MOD_LL, 2, "ll"},
	(t_scanf_mod){FT_SF_FLAG_SKIP, 1, "^"}
};

#endif
