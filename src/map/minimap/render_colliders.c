/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_colliders.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/13 20:58:37 by nsierra-         ###   ########.fr       */
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
	int column,
	int cell_size)
{
	double		tmp;
	t_player	*player;
	t_rect		collider;
	t_dvector	remainder;

	player = _player();
	remainder.x = modf(player->pos.x, &tmp) - PLAYER_START_POS_OFFSET - 0.2;
	remainder.y = modf(player->pos.y, &tmp) - PLAYER_START_POS_OFFSET - 0.2;
	rect_color_init(&collider, MINIMAP_COLLIDER_COLOR, MINIMAP_COLLIDER_COLOR);
	rect_square_init(
		&collider,
		(mmap->zone.start.x + cell_size * line)
		- (int)(cell_size * remainder.x),
		(mmap->zone.start.y + cell_size * column)
		- (int)(cell_size * remainder.y),
		cell_size)
	;
	rect_render_in_rect(&mmap->zone, &collider);
}

/*
** csize stands for cell_size
*/
void	minimap_render_colliders(t_minimap *mmap)
{
	int			line;
	int			column;
	int			csize;
	t_ivector	index;
	t_player	*player;

	index.x = 0;
	player = _player();
	line = (int)player->pos.x - player->sight;
	csize = mmap->zone.size.x / (player->sight * 2 + 1);
	while (line <= (int)player->pos.x + player->sight)
	{
		column = (int)player->pos.y - player->sight;
		index.y = 0;
		while (column <= (int)player->pos.y + player->sight)
		{
			if (tile_collides_by_pos(line, column))
				minimap_render_collider(mmap, index.x, index.y, csize);
			++column;
			++index.y;
		}
		++line;
		++index.x;
	}
}
