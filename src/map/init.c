/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/21 00:03:11 by nsierra-         ###   ########.fr       */
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

static t_bool	generate_map(t_map_candidate *candidate, t_map *map)
{
	int	line;
	int	column;

	line = 0;
	column = 0;
	map->data = ft_calloc(map->height, sizeof(t_tile *));
	if (map->data == NULL)
		return (fterr_set_error(E_MALLOC), FALSE);
	while (line < map->height)
	{
		map->data[line] = ft_calloc(map->width, sizeof(t_tile));
		if (map->data[line] == NULL)
			return (fterr_set_error(E_MALLOC), FALSE);
		column = 0;
		while (column < map->width)
		{
			map->data[line][column].type = candidate->matrix[line][column];
			++column;
		}
		++line;
	}
	return (TRUE);
}

static t_bool	map_from_candidate(t_map_candidate *candidate)
{
	t_map	*map;

	map = _map();
	map->height = candidate->height;
	map->width = candidate->width;
	map->filename = candidate->filename;
	map->color_ceiling = candidate->ceiling_color;
	map->color_floor = candidate->floor_color;
	map->texture_north.filename = ft_strdup(candidate->north_texture);
	map->texture_south.filename = ft_strdup(candidate->south_texture);
	map->texture_east.filename = ft_strdup(candidate->east_texture);
	map->texture_west.filename = ft_strdup(candidate->west_texture);
	if (!map->texture_north.filename || !map->texture_south.filename
		|| !map->texture_east.filename || !map->texture_west.filename)
		return (fterr_set_error(E_MALLOC), FALSE);
	else if (!map_candidate_build_matrix(candidate))
		return (FALSE);
	return (generate_map(candidate, map));
}

t_bool	map_init(char *filename)
{
	t_map_candidate	candidate;
	t_readf_status	status;

	ft_bzero(&candidate, sizeof(t_map_candidate));
	candidate.filename = filename;
	status = readf(filename, line_callback, &candidate);
	if (status == FTRF_E_READL)
		return (FALSE);
	else if (status == FTRF_E_FILE_OPEN)
		return (
			map_candidate_destroy(&candidate),
			fterr_set(E_MAP_OPEN, (void *)filename, NULL),
			FALSE
		);
	else if (&candidate.lines.size == 0)
		return (fterr_set(E_MAP_EMPTY, candidate.filename, NULL), FALSE);
	else if (!map_candidate_parse(&candidate)
		|| !map_candidate_is_valid(&candidate)
		|| !map_from_candidate(&candidate))
		return (map_candidate_destroy(&candidate), FALSE);
	return (map_candidate_destroy(&candidate), TRUE);
}
