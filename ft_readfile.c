/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:16:27 by snicolet          #+#    #+#             */
/*   Updated: 2016/11/10 17:23:48 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static size_t	ft_filesize(const char *filepath)
{
	struct stat		st;

	if (stat(filepath, &st) != 0)
		return (0);
	return ((size_t)st.st_size);
}

char			*ft_readfile(const char *filepath)
{
	const size_t	size = ft_filesize(filepath);
	ssize_t			ret;
	int				fd;
	char			*data;

	if ((!size) || (!(data = malloc(sizeof(char) * size))) ||
			(!(fd = open(filepath, O_RDONLY))))
		return (NULL);
	ret = read(fd, data, size);
	data[ret] = '\0';
	close(fd);
	return (data);
}
