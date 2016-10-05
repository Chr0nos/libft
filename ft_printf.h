/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:53:23 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/05 12:55:39 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdarg.h>
# include <inttypes.h>
# define FT_PRINTF_BSIZE		2048
# define FT_PRINTF_CONVERTS		"sSpdDioOuUxXcC"
# define FT_PRINTF_FLAGS		"#0-+ *"
# define FT_PRINTF_MODIFIERS	6

/*
** ft_printf flags
*/

# define FT_PRINTF_FLAGSNUM		5
# define FT_PRINTF_CONVS		15

# define FT_PRINTF_FLAG_DIESE	(1u << 0)
# define FT_PRINTF_FLAG_ZERO	(1u << 1)
# define FT_PRINTF_FLAG_LESS	(1u << 2)
# define FT_PRINTF_FLAG_MORE	(1u << 3)
# define FT_PRINTF_FLAG_SPACE	(1u << 4)
# define FT_PRINTF_MOD_H		(1u << 5)
# define FT_PRINTF_MOD_HH		(1u << 6)
# define FT_PRINTF_MOD_L		(1u << 7)
# define FT_PRINTF_MOD_LL		(1u << 8)
# define FT_PRINTF_MOD_J		(1u << 9)
# define FT_PRINTF_MOD_Z		(1u << 10)
# define FT_PRINTF_PREC			(1u << 11)
# define FT_PRINTF_MINFIELD		(1u << 12)

int					ft_printf(const char *s,
		...) __attribute__((format(printf,1,2)));

struct s_printf;

typedef struct		s_printf
{
	va_list			*ap;
	char			buffer[FT_PRINTF_BSIZE];
	char			*buff_start;
	unsigned int	flags;
	int				precision;
	int				fd;
	int				min_field;
	int				lastlen;
	int				padding;
	size_t			total_len;
	size_t			size;
	size_t			space_left;
	intmax_t		raw_value;
}					t_printf;

int					ft_printf_fd(int fd, const char *str, ...);
void				ft_printf_init(t_printf *pf, va_list *ap);
int					ft_printf_isaligned_right(t_printf *pf);
int					ft_printf_isaligned_left(t_printf *pf);
uintmax_t			ft_printf_conv_uint_getnb(t_printf *pf);
intmax_t			ft_printf_conv_int_getnb(t_printf *pf);
void				ft_printf_arg(t_printf *pf, size_t size);
size_t				ft_printf_loadall(t_printf *pf, const char *str);
void				ft_printf_append(t_printf *pf, const char *data,
	size_t len);
void				ft_printf_flush(t_printf *pf);
void				ft_printf_padding(t_printf *pf, const char c, int n);
void				ft_printf_convert_unknow(t_printf *pf, char c);

void				ft_printf_convert_int(t_printf *pf);
void				ft_printf_convert_str(t_printf *pf);
void				ft_printf_convert_percent(t_printf *pf);
void				ft_printf_convert_char(t_printf *pf);
void				ft_printf_convert_ptr(t_printf *pf);
void				ft_printf_convert_wchar(t_printf *pf);
void				ft_printf_convert_wstr(t_printf *pf);
void				ft_printf_convert_octal(t_printf *pf);
void				ft_printf_convert_uloctal(t_printf *pf);
void				ft_printf_convert_hex(t_printf *pf);
void				ft_printf_convert_uphex(t_printf *pf);
void				ft_printf_convert_upd(t_printf *pf);
void				ft_printf_convert_uint(t_printf *pf);
void				ft_printf_convert_upud(t_printf *pf);

/*
** conversions const global
*/

typedef struct		s_printf_convert
{
	int				letter;
	unsigned int	isnumeric;
	void			(*convert)(struct s_printf *);
	size_t			size;
}					t_printf_convert;

static const t_printf_convert g_printf_convs[FT_PRINTF_CONVS] = {
	(t_printf_convert){'d', 1, &ft_printf_convert_int, sizeof(int)},
	(t_printf_convert){'i', 1, &ft_printf_convert_int, sizeof(int)},
	(t_printf_convert){'s', 0, &ft_printf_convert_str, sizeof(char*)},
	(t_printf_convert){'%', 0, &ft_printf_convert_percent, sizeof(char)},
	(t_printf_convert){'c', 0, &ft_printf_convert_char, sizeof(char)},
	(t_printf_convert){'p', 1, &ft_printf_convert_ptr, sizeof(void*)},
	(t_printf_convert){'C', 0, &ft_printf_convert_wchar, sizeof(wchar_t)},
	(t_printf_convert){'S', 0, &ft_printf_convert_wstr, sizeof(wchar_t *)},
	(t_printf_convert){'o', 1, &ft_printf_convert_octal, sizeof(int)},
	(t_printf_convert){'O', 1, &ft_printf_convert_uloctal, sizeof(long int)},
	(t_printf_convert){'x', 1, &ft_printf_convert_hex, sizeof(int)},
	(t_printf_convert){'X', 1, &ft_printf_convert_uphex, sizeof(int)},
	(t_printf_convert){'D', 1, &ft_printf_convert_upd, sizeof(long int)},
	(t_printf_convert){'u', 1, &ft_printf_convert_uint, sizeof(unsigned int)},
	(t_printf_convert){'U', 1, &ft_printf_convert_upud, sizeof(long int)}
};

/*
** flags const global
*/

typedef struct		s_printf_cfg
{
	int				letter;
	unsigned int	flag;
	unsigned int	mask;
	int				padding;
}					t_printf_cfg;

static const t_printf_cfg g_printf_cfg[FT_PRINTF_FLAGSNUM] = {
	(t_printf_cfg){'#', FT_PRINTF_FLAG_DIESE, ~0u, 0},
	(t_printf_cfg){'0', FT_PRINTF_FLAG_ZERO, ~0u, 0},
	(t_printf_cfg){'-', FT_PRINTF_FLAG_LESS, ~(FT_PRINTF_FLAG_ZERO), 0},
	(t_printf_cfg){'+', FT_PRINTF_FLAG_MORE, ~(FT_PRINTF_FLAG_SPACE), 0},
	(t_printf_cfg){' ', FT_PRINTF_FLAG_SPACE, ~FT_PRINTF_FLAG_MORE, 0}
};

/*
** modifiers const global
*/

typedef struct		s_printf_modif
{
	const char		*modifier;
	unsigned int	flag;
	unsigned int	mask;
	size_t			len;
}					t_printf_modif;

static const t_printf_modif g_printf_modifiers[FT_PRINTF_MODIFIERS] = {
	(t_printf_modif){"h", FT_PRINTF_MOD_H,
		~(FT_PRINTF_MOD_L | FT_PRINTF_MOD_LL), 1},
	(t_printf_modif){"hh", FT_PRINTF_MOD_HH, ~0u, 2},
	(t_printf_modif){"l", FT_PRINTF_MOD_L, ~0u, 1},
	(t_printf_modif){"ll", FT_PRINTF_MOD_LL, ~0u, 2},
	(t_printf_modif){"j", FT_PRINTF_MOD_J, ~0u, 1},
	(t_printf_modif){"z", FT_PRINTF_MOD_Z, ~0u, 1}
};

#endif
