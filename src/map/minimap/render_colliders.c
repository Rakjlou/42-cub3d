/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_colliders.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/13 20:19:26 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/window.h"
#include "map/minimap.h"
#include "map/map_tile.h"
#include "player.h"

static void	minimap_render_collider(
	t_minimap *mmap,
	int line,
	int column,
	int cell_size)
{
	t_rect	collider;

	rect_color_init(&collider, MINIMAP_COLLIDER_COLOR, MINIMAP_COLLIDER_COLOR);
	rect_square_init(
		&collider,
		mmap->zone.start.x + cell_size * line,
		mmap->zone.start.y + cell_size * column,
		cell_size)
	;
	rect_render(&collider);
}

void	minimap_render_colliders(t_minimap *mmap)
{
	int			line;
	int			column;
	int			cell_size;
	t_ivector	index;
	t_player	*player;

	index.x = 0;
	player = _player();
	line = (int)player->pos.x - player->sight;
	cell_size = mmap->zone.size.x / (player->sight * 2 + 1);
	while (line <= (int)player->pos.x + player->sight)
	{
		column = (int)player->pos.y - player->sight;
		index.y = 0;
		while (column <= (int)player->pos.y + player->sight)
		{
			if (tile_collides_by_pos(line, column))
				minimap_render_collider(mmap, index.x, index.y, cell_size);
			++column;
			++index.y;
		}
		++line;
		++index.x;
	}
}
