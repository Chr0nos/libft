#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#define EXIT_ERROR 1
#define EXIT_ERROR_OPEN 2

int		main(int ac, char **av)
{
	const char		*filepath = av[1];
	int				fd;
	char			*line;
	char			content[100];

	if (ac < 2)
		return (EXIT_ERROR);
	fd = open(filepath, O_RDONLY);
	if (!fd)
		return (EXIT_ERROR_OPEN);
	ft_putstr("calling gnl\n");
	while (ft_get_next_line(fd, &line) > 0)
	{
		ft_putstr("going to sscanf\n");
		if (ft_sscanf(line, "\twhile %100c", content) == 1)
			ft_putendl(content);
		free(line);
	}
	close(fd);
	ft_putstr("ok it's fine\n");
	return (EXIT_SUCCESS);
}
