/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/11 22:10:18 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/map.h"

t_tile	*map_get_tile(int line, int column)
{
	t_map	*map;

	map = _map();
	if (line < 0 || line >= map->height || column < 0 || column >= map->width)
		return (NULL);
	return (&map->tiles[line][column]);
}
