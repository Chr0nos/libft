/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 19:20:46 by snicolet          #+#    #+#             */
/*   Updated: 2017/06/07 22:14:18 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCANF_H
# define FT_SCANF_H
# include <stdarg.h>
# include <string.h>

# define FT_SF_CONVERTS	"dswfxo%Nnv"

# define FT_SF_QUIT			(1u << 0)
# define FT_SF_ERROR		(1u << 1)
# define FT_SF_MOD_HH		(1u << 2)
# define FT_SF_MOD_H		(1u << 3)
# define FT_SF_MOD_L		(1u << 4)
# define FT_SF_MOD_LL		(1u << 5)
# define FT_SF_MOD_J		(1u << 6)
# define FT_SF_MOD_Z		(1u << 7)
# define FT_SF_MOD_NONE		(1u << 8)
# define FT_SF_FLAG_SKIP	(1u << 9)
# define FT_SF_FLAG_PREC	(1u << 10)
# define FT_SF_FLAG_MAXLEN  (1u << 11)
# define FT_SF_MOD_ANYI		0xf0
# define FT_SF_MOD_ANYD		0x0c
# define FT_SF_MOD_ANY		0xfc
# define FT_SF_SPACE		(char *)(size_t)" \t\n\r\v"
# define FT_SF_DIGIT		(char *)(size_t)"0123456789+-."

/*
** ft_sscanf documentation:
** flags:
** *  : pretends to do the conversion but does nothing, it allow to skip things
** h  : read as short size
** hh : read a char size
** ll : read as long long
** l  : read as long
** -----------------------------------------------------------------------------
** %s : retrive all the left text in the parsed string
** modifiers: precision / maxlen
** if maxlen AND precision are given, precision will be used, other is ignored
** -----------------------------------------------------------------------------
** %d : retrive int data
** modifiers: H HH L ll j z
** -----------------------------------------------------------------------------
** %x : retrive hexadecimal text into a unsigned int
** modifiers: H HH L LL
** -----------------------------------------------------------------------------
** %o : retrive octal value from text into unsigned long
** modifiers: H HH
** -----------------------------------------------------------------------------
** %f : read a float into passed variable pointer
** modifiers: L / LL
** -----------------------------------------------------------------------------
** %w : retrive the current word in the parsed string
** modifiers: precision
** -----------------------------------------------------------------------------
** %k : execute a custom function (provided by user)
** modifiers: none ! not even '*'
** but they are given to the kernel into sf->flags, do what you wan with them
** -----------------------------------------------------------------------------
** %n : set the current validated lenght in given string into a size_t
** modifiers:
**     h : target is a int
** all other modifiers will be ignored
** -----------------------------------------------------------------------------
** %v : load a vector, important: this need to have the size of vector specified
** by default the vector type is float
** to modify type:
** hh = char vector
** h = int vector
** l = double vector
** the parser also needs to get the vector size, ex;
** %4v = float[4]
** %3hv = int[3]
** %4lv = double[4]
** the flag * is set the function just count
** there is no any other flags supported by this parser
** note: each vector could be separated by " \t\n\r\v" (like as \\S skipper)
** the return code will be incrased by 1 if the vector has been fully parsed
** in case of only 3 vectors set in a vector 4, the ret code will not be
** incrased at all
** -----------------------------------------------------------------------------
** %N : set the current position pointer (char **) into the given string
** -----------------------------------------------------------------------------
** %$ : check for the end of given string
** modifiers: none
** set nothing, just incrase by one the number of items done (don't take arg)
** -----------------------------------------------------------------------------
** skipers:
** \w : skip the next word
** \s : skip all next consecutives spaces
** \S : skip all next consecutives spaces/tab/new lines/and \v
** \n : skip unti the next new line (if no new line, this will stop the parsing)
** note: if the "skip" element is not there. no error will be retuned because
** skipers are optionals, that the main difference between them and a %*
** -----------------------------------------------------------------------------
** of course all converions have flag * supported
*/

typedef struct		s_scanf
{
	va_list			*ap;
	const char		*str;
	const char		*str_origin;
	const char		*format;
	int				total_len;
	unsigned int	flags;
	unsigned int	flags_mask;
	int				precision;
	unsigned int	min_width;
	unsigned int	arg_done;
	int				maxlen;
	int				padding;
}					t_scanf;

int					ft_sscanf(const char *s, const char *format, ...);
int					ft_sscanfq(const char *s, const char *format, ...);
int					ft_sscanfqf(const char *s, const char *format, ...);
const char			*ft_scanf_loadmods(const char *format, t_scanf *sf);
unsigned int		ft_scanf_engine(const char *format, t_scanf *sf);

/*
** setters functions, they are all used as functions pointer
** in ft_scanf_exec (static)
*/

int					ft_scanf_set_int(t_scanf *sf);
int					ft_scanf_set_str(t_scanf *sf);
int					ft_scanf_set_word(t_scanf *sf);
int					ft_scanf_set_float(t_scanf *sf);
int					ft_scanf_set_kernel(t_scanf *sf);
int					ft_scanf_set_hex(t_scanf *sf);
int					ft_scanf_set_octal(t_scanf *sf);
int					ft_scanf_set_percent(t_scanf *sf);
int					ft_scanf_set_upn(t_scanf *sf);
int					ft_scanf_set_n(t_scanf *sf);
int					ft_scanf_set_end(t_scanf *sf);
int					ft_scanf_set_vec(t_scanf *sf);

/*
** lenght calculation functions
*/

int					ft_scanf_set_int_len(const t_scanf *sf);
int					ft_scanf_set_float_len(const char *str);

typedef struct		s_scanf_set
{
	int				letter;
	int				flags;
	int				(*set)(t_scanf *sf);
}					t_scanf_set;

# define FT_SF_CONVCOUNT 11

static const t_scanf_set g_scanf_set[FT_SF_CONVCOUNT] = {
	(t_scanf_set){'%', 0, ft_scanf_set_percent},
	(t_scanf_set){'$', 0, ft_scanf_set_end},
	(t_scanf_set){'N', 0, ft_scanf_set_upn},
	(t_scanf_set){'n', 0, ft_scanf_set_n},
	(t_scanf_set){'w', 0, ft_scanf_set_word},
	(t_scanf_set){'v', 0, ft_scanf_set_vec},
	(t_scanf_set){'f', 0, ft_scanf_set_float},
	(t_scanf_set){'x', 0, ft_scanf_set_hex},
	(t_scanf_set){'o', 0, ft_scanf_set_octal},
	(t_scanf_set){'d', 0, ft_scanf_set_int},
	(t_scanf_set){'s', 0, ft_scanf_set_str}
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

# define FT_SF_MODS_COUNT 7

static const t_scanf_mod g_scanf_mods[FT_SF_MODS_COUNT] = {
	(t_scanf_mod){FT_SF_MOD_J, 1, "j"},
	(t_scanf_mod){FT_SF_MOD_Z, 1, "z"},
	(t_scanf_mod){FT_SF_MOD_H, 1, "h"},
	(t_scanf_mod){FT_SF_MOD_HH, 2, "hh"},
	(t_scanf_mod){FT_SF_MOD_L, 1, "l"},
	(t_scanf_mod){FT_SF_MOD_LL, 2, "ll"},
	(t_scanf_mod){FT_SF_FLAG_SKIP, 1, "*"}

};

#endif
