/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:20:35 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 23:22:07 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readf.h"
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

t_readf_status	readf(
	const char *filename,
	t_bool (*readl)(const char *, void *),
	void *data)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		return (FTRF_E_FILE_OPEN);
	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		else if (readl != NULL && !readl(line, data))
			return (free(line), gnl_close(fd), FTRF_E_READL);
		free(line);
	}
	gnl_close(fd);
	return (FTRF_SUCCESS);
}
