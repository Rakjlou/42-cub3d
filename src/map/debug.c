/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/20 22:21:25 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftprintf.h"
#include "map/map.h"

static void	print_data(t_map *map)
{
	int	line;
	int	column;

	line = 0;
	ftprintf("--- DATA ---\n");
	while (line < map->height)
	{
		column = 0;
		ftprintf(">");
		while (column < map->width)
		{
			ftprintf("%c", map->data[line][column].type);
			++column;
		}
		ftprintf("<\n");
		++line;
	}
}

void	map_debug(void)
{
	t_map	*map;

	map = _map();
	ftprintf("vvv MAP DEBUG vvv\n");
	ftprintf("Filename: %s\n", map->filename);
	ftprintf("Height:   %d\n", map->height);
	ftprintf("Width:    %d\n", map->width);
	ftprintf("NO:       %s\n", map->texture_north.filename);
	ftprintf("SO:       %s\n", map->texture_south.filename);
	ftprintf("EA:       %s\n", map->texture_east.filename);
	ftprintf("WE:       %s\n", map->texture_west.filename);
	ftprintf("F:        %X\n", map->color_floor);
	ftprintf("C:        %X\n", map->color_ceiling);
	print_data(map);
	ftprintf("^^^ MAP DEBUG ^^^\n");
}
