#include "libft.h"
#include <stdlib.h>

int		ft_scanf_set_char(t_scanf *sf)
{
	size_t			len;
	char			*str;

	str = va_arg(*sf->ap, char*);
	if (!str)
	{
		sf->flags |= FT_SF_QUIT | FT_SF_ERROR;
		return (1);
	}
	len = ft_strplen(sf->str,
			&sf->str[(sf->flags & FT_SF_FLAG_PREC) ? sf->precision : 1]);
	ft_strncpy(str, sf->str, len);
	sf->str += len;
	return (1);
}
