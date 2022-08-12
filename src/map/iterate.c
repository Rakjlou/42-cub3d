/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/11 23:01:40 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/map.h"
#include "player.h"

void	map_iterate(void (*callback)(t_tile *))
{
	t_map	*map;
	int		line;
	int		column;

	map = _map();
	line = 0;
	while (line < map->height)
	{
		column = 0;
		while (column < map->width)
		{
			callback(&map->tiles[line][column]);
			++column;
		}
		++line;
	}
}
