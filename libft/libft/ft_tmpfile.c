/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tmpfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:51:35 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/08 23:06:15 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"

static char	*tmpfile_filepath(int i)
{
	char	*base;
	char	*filepath;
	char	*num;

	base = "/tmp/.libft-";
	num = ft_itoa(i);
	if (num == NULL)
		return (NULL);
	filepath = ft_strjoin(base, num);
	return (free(num), filepath);
}

int	ft_tmpfile(char **filepath)
{
	int		i;
	int		fd;
	char	*path;

	i = 0;
	while (42)
	{
		path = tmpfile_filepath(i);
		if (path == NULL)
			return (0);
		fd = open(
				path,
				O_CREAT | O_EXCL | O_RDWR,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
		if (fd <= 0 && errno == EEXIST)
			free(path);
		else if (fd <= 0)
			return (free(path), fd);
		else
		{
			*filepath = path;
			return (fd);
		}
		++i;
	}
}
