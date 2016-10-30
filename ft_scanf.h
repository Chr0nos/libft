/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 19:20:46 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/30 19:43:40 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCANF
# define FT_SCANF

# define FT_SF_QUIT		(1u << 0)
# define FT_SF_ERROR	(1u << 1)

typedef struct		s_scanf
{
	va_list			*ap;
	int				total_len;
	unsigned int	flags;
}					t_scanf;


int					ft_sscanf(const char *s, const char *format, ...);

#endif
