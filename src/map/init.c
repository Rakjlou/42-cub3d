/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/01 21:04:15 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map/map_candidate.h"
#include "map/map.h"
#include "errors.h"
#include "libft.h"
#include "readf.h"
#include "fterr.h"
#include "ftprintf.h"

static t_bool	line_callback(const char *line, void *data)
{
	t_map_candidate	*candidate;
	char			*dup_line;

	candidate = (t_map_candidate *)data;
	dup_line = ft_strdup(line);
	if (dup_line == NULL)
		return (fterr_set_error(E_MALLOC), FALSE);
	else if (lst_push_back(&candidate->lines, dup_line) == 0)
		return (fterr_set_error(E_MALLOC), FALSE);
	return (TRUE);
}

t_map	*map_init(char *filename)
{
	t_map_candidate	candidate;
	t_readf_status	status;

	ft_bzero(&candidate, sizeof(t_map_candidate));
	candidate.filename = filename;
	status = readf(filename, line_callback, &candidate);
	if (status == FTRF_E_READL)
		return (NULL);
	else if (status == FTRF_E_FILE_OPEN)
		return (
			map_candidate_destroy(&candidate),
			fterr_set(E_MAP_OPEN, (void *)filename, NULL),
			NULL
		);
	else if (&candidate.lines.size == 0)
		return (fterr_set(E_MAP_EMPTY, candidate.filename, NULL), NULL);
	else if (!map_candidate_parse(&candidate)
		|| !map_candidate_is_valid(&candidate))
		return (map_candidate_destroy(&candidate), NULL);
	return (map_candidate_destroy(&candidate), NULL);
}
