/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 19:20:46 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/30 20:20:42 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCANF
# define FT_SCANF

# define FT_SF_CONVERTS	"ds"

# define FT_SF_QUIT		(1u << 0)
# define FT_SF_ERROR	(1u << 1)
# define FT_SF_MOD_HH	(1u << 2)
# define FT_SF_MOD_H	(1u << 3)
# define FT_SF_MOD_L	(1u << 4)
# define FT_SF_MOD_LL	(1u << 5)

typedef struct		s_scanf
{
	va_list			*ap;
	const char		*str;
	int				total_len;
	unsigned int	flags;
}					t_scanf;


int					ft_sscanf(const char *s, const char *format, ...);

/*
** setters functions, they are all used as functions pointer
** in ft_scanf_exec (static)
*/

int					ft_scanf_set_int(t_scanf *sf);
int					ft_scanf_set_str(t_scanf *sf);

typedef struct		s_scanf_set
{
	int				letter;
	int				flags;
	int				(*set)(t_scanf *sf);
}					t_scanf_set;

# define FT_SF_CONVERTS 2

static const t_scanf_set g_scanf_set[FT_SF_CONVERTS] = {
	(t_scanf_set){'d', 0, ft_scanf_set_int},
	(t_scanf_set){'s', 0, ft_scanf_set_str}
};

#endif
