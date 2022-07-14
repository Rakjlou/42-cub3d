/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:07:37 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/14 04:08:57 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/map_validation.h"

static t_bool	check_floor(t_map_candidate *candidate, int line, int column);

static t_bool	is_map_border(t_map_candidate *candidate, int line, int column)
{
	int	height;
	int	width;
	int	llimit;
	int	climit;

	height = candidate->height;
	width = candidate->width;
	llimit = height - 1;
	climit = width - 1;
	return (line == 0 || column == 0 || line == llimit || column == climit);
}

static t_bool	check_floor_surrounding(
	t_map_candidate *candidate,
	int line,
	int column)
{
	int	tile;

	tile = candidate->matrix[line][column];
	if (tile_is_floor(tile) && !check_floor(candidate, line, column))
		return (FALSE);
	return (!tile_is_outside(tile));
}

static t_bool	check_floor(t_map_candidate *candidate, int line, int column)
{
	if (is_map_border(candidate, line, column))
		return (FALSE);
	candidate->matrix[line][column] = FLOOR_VALIDATION;
	if (!check_floor_surrounding(candidate, line, column - 1)
		|| !check_floor_surrounding(candidate, line, column + 1)
		|| !check_floor_surrounding(candidate, line - 1, column)
		|| !check_floor_surrounding(candidate, line + 1, column))
		return (FALSE);
	return (TRUE);
}

t_bool	check_walls(t_map_candidate *candidate)
{
	int	line;
	int	column;
	int	tile;

	line = 0;
	while (line < candidate->height)
	{
		column = 0;
		while (column < candidate->width)
		{
			tile = candidate->matrix[line][column];
			if (tile_is_floor(tile) && !check_floor(candidate, line, column))
				return (fterr_set_error(E_MAP_HOLE), FALSE);
			++column;
		}
		++line;
	}
	return (TRUE);
}
