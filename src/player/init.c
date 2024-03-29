/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/13 20:20:07 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/map.h"
#include "map/map_validation.h"
#include "player.h"

static void	set_direction(t_tile *tile)
{
	_player()->dir.x = 0;
	_player()->dir.y = 0;
	_player()->fov.x = 0;
	_player()->fov.y = 0;
	if (tile_is(tile, *SPAWN_NORTH))
	{
		_player()->dir.x = -1;
		_player()->fov.y = PLAYER_DEFAULT_FOV;
	}
	else if (tile_is(tile, *SPAWN_SOUTH))
	{
		_player()->dir.x = 1;
		_player()->fov.y = -PLAYER_DEFAULT_FOV;
	}
	else if (tile_is(tile, *SPAWN_EAST))
	{
		_player()->dir.y = 1;
		_player()->fov.x = PLAYER_DEFAULT_FOV;
	}
	else if (tile_is(tile, *SPAWN_WEST))
	{
		_player()->dir.y = -1;
		_player()->fov.x = -PLAYER_DEFAULT_FOV;
	}
}

static void	set_initial_values(t_tile *tile)
{
	if (ft_strchr(SPAWN_CHARS, tile->type) != NULL)
	{
		_player()->speed = PLAYER_DEFAULT_SPEED;
		_player()->rotation_speed = PLAYER_DEFAULT_ROTATION_SPEED;
		_player()->pos.x = tile->x + PLAYER_START_POS_OFFSET;
		_player()->pos.y = tile->y + PLAYER_START_POS_OFFSET;
		_player()->sight = PLAYER_DEFAULT_MINIMAP_SIGHT;
		set_direction(tile);
	}
}

void	player_init(void)
{
	map_iterate(set_initial_values);
}
