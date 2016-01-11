#include "libft.h"

int		ft_strcasecmp(const char *s1, const char *s2)
{
	int		p;

	p = 0;
	while ((s1[p]) && (ft_tolower(s1[p]) == ft_tolower(s2[p])))
		p++;
	return (ft_tolower(s1[p]) - ft_tolower(s2[p]));
}
