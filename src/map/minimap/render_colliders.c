/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_colliders.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/14 13:11:15 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/window.h"
#include "map/minimap.h"
#include "map/map_tile.h"
#include "player.h"
#include <math.h>
#include <stdio.h>

static void	minimap_render_collider(
	t_minimap *mmap,
	int line,
	int column)
{
	double		tmp;
	t_player	*player;
	t_rect		collider;
	t_dvector	remainder;

	player = _player();
	remainder.x = modf(player->pos.x, &tmp) - PLAYER_START_POS_OFFSET - 0.1;
	remainder.y = modf(player->pos.y, &tmp) - PLAYER_START_POS_OFFSET - 0.1;
	rect_color_init(&collider, MINIMAP_COLLIDER_COLOR, MINIMAP_COLLIDER_COLOR);
	rect_square_init(
		&collider,
		(mmap->zone.start.x + mmap->tile_size * line)
		- (int)(mmap->tile_size * remainder.x),
		(mmap->zone.start.y + mmap->tile_size * column)
		- (int)(mmap->tile_size * remainder.y),
		mmap->tile_size)
	;
	rect_render_in_rect(&mmap->zone, &collider);
}

/*
** Line/index.x and column/index.y are set to -1 and iterate +1 because we want
** to print the next partial cell in order to have a fluid minimap.
*/
void	minimap_render_colliders(t_minimap *mmap)
{
	int			line;
	int			column;
	t_ivector	index;
	t_player	*player;

	player = _player();
	index.x = -1;
	line = (int)player->pos.x - player->sight - 1;
	while (line <= (int)player->pos.x + player->sight + 1)
	{
		index.y = -1;
		column = (int)player->pos.y - player->sight - 1;
		while (column <= (int)player->pos.y + player->sight + 1)
		{
			if (tile_collides_by_pos(line, column))
				minimap_render_collider(mmap, index.x, index.y);
			++column;
			++index.y;
		}
		++line;
		++index.x;
	}
}
