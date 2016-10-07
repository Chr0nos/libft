/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:53:23 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/07 02:20:13 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdarg.h>
# include <inttypes.h>
# define FT_PF_BSIZE		8192
# define FT_PF_CONVERTS		"sSpdDioOuUxXcC"
# define FT_PF_FLAGS		"#0-+ *"
# define FT_PF_MODIFIERS	6

/*
**         [-+sign]
**         [    0x]
** [space] [prefix] [zero] [digit/str] [rspace]
**                         [---------]				(pf->raw_len)
**         [-------------------------]				(pf->slen)
** [------------------------------------------]		(>= pf->min_width)
*/

/*
** ft_printf flags
*/

# define FT_PF_FLAGSNUM		5
# define FT_PF_CONVS		15

# define FT_PF_FLAG_DIESE	(1u << 0)
# define FT_PF_FLAG_ZERO	(1u << 1)
# define FT_PF_FLAG_LESS	(1u << 2)
# define FT_PF_FLAG_MORE	(1u << 3)
# define FT_PF_FLAG_SPACE	(1u << 4)
# define FT_PF_MOD_H		(1u << 5)
# define FT_PF_MOD_HH		(1u << 6)
# define FT_PF_MOD_L		(1u << 7)
# define FT_PF_MOD_LL		(1u << 8)
# define FT_PF_MOD_J		(1u << 9)
# define FT_PF_MOD_Z		(1u << 10)
# define FT_PF_PREC			(1u << 11)
# define FT_PF_MINWIDTH		(1u << 12)
# define FT_PF_PTR			(1u << 13)
# define FT_PF_NUMERIC		(1u << 14)

int					ft_printf(const char *s,
		...) __attribute__((format(printf,1,2)));

struct s_printf;

typedef struct		s_printf
{
	va_list			*ap;
	char			buffer[FT_PF_BSIZE];
	char			*buff_start;
	unsigned int	flags;
	int				precision;
	int				fd;
	int				min_width;
	int				lastlen;
	int				raw_len;
	int				slen;
	int				padding;
	size_t			total_len;
	size_t			size;
	size_t			space_left;
	intmax_t		raw_value;
}					t_printf;

int					ft_printf_fd(int fd, const char *str, ...);
int					ft_printf(const char *str, ...);
void				ft_printf_init(t_printf *pf, va_list *ap);
int					ft_printf_isaligned_right(t_printf *pf);
int					ft_printf_isaligned_left(t_printf *pf);
uintmax_t			ft_printf_conv_uint_getnb(t_printf *pf);
intmax_t			ft_printf_conv_int_getnb(t_printf *pf);
size_t				ft_printf_loadall(t_printf *pf, const char *str);
size_t				ft_printf_append(t_printf *pf, const char *data,
	size_t len);
void				ft_printf_flush(t_printf *pf);
int					ft_printf_padding(t_printf *pf, const char c, int n);
void				ft_printf_align_left(t_printf *pf, int len);
void				ft_printf_conv(t_printf *pf, const char c);
void				ft_pf_fixprecision_null(t_printf *pf, int *len);

void				ft_pf_arg_nbr(t_printf *pf);
void				ft_pf_arg_unbr(t_printf *pf);
void				ft_pf_arg_ptr(t_printf *pf);
void				ft_pf_arg_char(t_printf *pf);
void				ft_pf_arg_upd(t_printf *pf);
void				ft_pt_arg_pc(t_printf *pf);
void				ft_pf_arg_wchar(t_printf *pf);

void				ft_pf_conv_unknow(t_printf *pf, char c);
void				ft_pf_conv_int(t_printf *pf);
void				ft_pf_conv_str(t_printf *pf);
void				ft_pf_conv_percent(t_printf *pf);
void				ft_pf_conv_char(t_printf *pf);
void				ft_pf_conv_ptr(t_printf *pf);
void				ft_pf_conv_wchar(t_printf *pf);
void				ft_pf_conv_wstr(t_printf *pf);
void				ft_pf_conv_octal(t_printf *pf);
void				ft_pf_conv_hex(t_printf *pf);
void				ft_pf_conv_uphex(t_printf *pf);
void				ft_pf_conv_uint(t_printf *pf);
void				ft_pf_conv_upud(t_printf *pf);

void				ft_pf_len_char(t_printf *pf);
void				ft_pf_len_int(t_printf *pf);
void				ft_pf_len_uint(t_printf *pf);
void				ft_pf_len_str(t_printf *pf);
void				ft_pf_len_wstr(t_printf *pf);
void				ft_pf_len_upd(t_printf *pf);
void				ft_pf_len_hex(t_printf *pf);
void				ft_pf_len_octal(t_printf *pf);

/*
** conversions const global
*/

typedef struct		s_printf_convert
{
	int				letter;
	unsigned short	isnumeric;
	unsigned short	isptr;
	void			(*convert)(struct s_printf *);
	void			(*set_len)(t_printf *pf);
	void			(*get_arg)(t_printf *pf);
}					t_printf_convert;

# define TCO t_printf_convert

static const t_printf_convert g_printf_convs[FT_PF_CONVS] = {
	(TCO){'d', 1, 0, &ft_pf_conv_int, &ft_pf_len_int, &ft_pf_arg_nbr},
	(TCO){'i', 1, 0, &ft_pf_conv_int, &ft_pf_len_int, &ft_pf_arg_nbr},
	(TCO){'s', 0, 1, &ft_pf_conv_str, &ft_pf_len_str, &ft_pf_arg_ptr},
	(TCO){'%', 0, 0, &ft_pf_conv_percent, &ft_pf_len_char, &ft_pt_arg_pc},
	(TCO){'c', 0, 0, &ft_pf_conv_char, &ft_pf_len_char, &ft_pf_arg_char},
	(TCO){'p', 1, 1, &ft_pf_conv_ptr, &ft_pf_len_hex, &ft_pf_arg_ptr},
	(TCO){'C', 0, 0, &ft_pf_conv_wchar, &ft_pf_len_char, &ft_pf_arg_wchar},
	(TCO){'S', 0, 1, &ft_pf_conv_wstr, &ft_pf_len_wstr, &ft_pf_arg_ptr},
	(TCO){'o', 1, 0, &ft_pf_conv_octal, &ft_pf_len_octal, &ft_pf_arg_unbr},
	(TCO){'O', 1, 0, &ft_pf_conv_octal, &ft_pf_len_octal, &ft_pf_arg_upd},
	(TCO){'x', 1, 0, &ft_pf_conv_hex, &ft_pf_len_hex, &ft_pf_arg_unbr},
	(TCO){'X', 1, 0, &ft_pf_conv_uphex, &ft_pf_len_hex, &ft_pf_arg_unbr},
	(TCO){'D', 1, 0, &ft_pf_conv_int, &ft_pf_len_upd, &ft_pf_arg_upd},
	(TCO){'u', 1, 0, &ft_pf_conv_uint, &ft_pf_len_uint, &ft_pf_arg_unbr},
	(TCO){'U', 1, 0, &ft_pf_conv_upud, &ft_pf_len_uint, &ft_pf_arg_upd}
};

/*
** flags const global
*/

typedef struct		s_printf_cfg
{
	int				letter;
	unsigned int	flag;
	unsigned int	mask;
	unsigned int	refuse;
}					t_printf_cfg;

static const t_printf_cfg g_printf_cfg[FT_PF_FLAGSNUM] = {
	(t_printf_cfg){'#', FT_PF_FLAG_DIESE, ~0u, 0},
	(t_printf_cfg){'0', FT_PF_FLAG_ZERO, ~0u, 0},
	(t_printf_cfg){'-', FT_PF_FLAG_LESS, ~0u, 0},
	(t_printf_cfg){'+', FT_PF_FLAG_MORE, ~(FT_PF_FLAG_SPACE), 0},
	(t_printf_cfg){' ', FT_PF_FLAG_SPACE, ~0u, FT_PF_FLAG_MORE}
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

static const t_printf_modif g_printf_modifiers[FT_PF_MODIFIERS] = {
	(t_printf_modif){"h", FT_PF_MOD_H, ~(FT_PF_MOD_L | FT_PF_MOD_LL), 1},
	(t_printf_modif){"hh", FT_PF_MOD_HH, ~0u, 2},
	(t_printf_modif){"l", FT_PF_MOD_L, ~0u, 1},
	(t_printf_modif){"ll", FT_PF_MOD_LL, ~0u, 2},
	(t_printf_modif){"j", FT_PF_MOD_J, ~0u, 1},
	(t_printf_modif){"z", FT_PF_MOD_Z, ~0u, 1}
};

#endif
