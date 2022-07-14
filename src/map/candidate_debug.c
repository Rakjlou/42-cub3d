/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   candidate_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/14 01:00:27 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftprintf.h"
#include "map/map_candidate.h"

static void	print_raw_lines(t_map_candidate *candidate)
{
	t_iter	iter;

	ftprintf("--- LINES ---\n");
	iter_init(&iter, &candidate->lines, ASC);
	while (iter_next(&iter))
		ftprintf("%s", (char *)iter.data);
}

static void	print_raw_meta(t_map_candidate *candidate)
{
	t_iter	iter;

	ftprintf("--- META ---\n");
	iter_init(&iter, &candidate->meta, ASC);
	while (iter_next(&iter))
		ftprintf("%s\n", (char *)iter.data);
}

static void	print_raw_map(t_map_candidate *candidate)
{
	t_iter	iter;

	ftprintf("--- MAP ---\n");
	iter_init(&iter, &candidate->map, ASC);
	while (iter_next(&iter))
		ftprintf("%s\n", (char *)iter.data);
}

static void	print_matrix(t_map_candidate *candidate)
{
	int	line;
	int	column;

	line = 0;
	ftprintf("--- MATRIX ---\n");
	while (line < candidate->height)
	{
		column = 0;
		ftprintf(">");
		while (column < candidate->width)
		{
			ftprintf("%c", candidate->matrix[line][column]);
			++column;
		}
		ftprintf("<\n");
		++line;
	}
}

void	map_candidate_debug(t_map_candidate *candidate)
{
	ftprintf("vvv MAP CANDIDATE DEBUG vvv\n");
	ftprintf("Filename: %s\n", candidate->filename);
	ftprintf("Height:   %d\n", candidate->height);
	ftprintf("Width:    %d\n", candidate->width);
	ftprintf("NO:       %s\n", candidate->north_texture);
	ftprintf("SO:       %s\n", candidate->south_texture);
	ftprintf("EA:       %s\n", candidate->east_texture);
	ftprintf("WE:       %s\n", candidate->west_texture);
	ftprintf("F:        %X\n", candidate->floor_color);
	ftprintf("C:        %X\n", candidate->ceilling_color);
	print_raw_lines(candidate);
	print_raw_meta(candidate);
	print_raw_map(candidate);
	print_matrix(candidate);
	ftprintf("^^^ MAP CANDIDATE DEBUG ^^^\n");
}
