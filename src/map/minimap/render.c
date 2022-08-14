/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/14 13:32:32 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/window.h"
#include "render/circle.h"
#include "render/rect.h"
#include "map/minimap.h"
#include "player.h"
#include "libft.h"

static void	minimap_render_player(t_minimap *mmap)
{
	t_circle	dot;

	rect_get_center(&mmap->zone, &dot.origin);
	dot.radius = 4;
	dot.fill_color = MINIMAP_PLAYER_DOT_COLOR;
	dot.border_color = MINIMAP_PLAYER_DOT_COLOR;
	render_circle(&dot);
}

static void	minimap_setup(t_minimap *mmap)
{
	int	start_y;

	ft_bzero(mmap, sizeof(t_minimap));
	mmap->size = (int)(ft_min(WINDOW_WIDTH, WINDOW_HEIGHT) * 0.25);
	start_y = WINDOW_WIDTH - mmap->size - MINIMAP_OFFSET;
	rect_square_init(&mmap->zone, MINIMAP_OFFSET, start_y, mmap->size);
	rect_color_init(&mmap->zone, COLOR_TRANSPARENT, COLOR_RED);
	rect_get_center(&mmap->zone, &mmap->center);
	mmap->tile_size = mmap->zone.size.x / (_player()->sight * 2 + 1);
}

static void	minimap_render_direction(t_minimap *mmap)
{
	t_player	*player;
	t_circle	dot;

	player = _player();
	dot.radius = 4;
	dot.fill_color = MINIMAP_PLAYER_DIR_COLOR;
	dot.border_color = MINIMAP_PLAYER_DIR_COLOR;
	mmap->center.x = mmap->center.x;
	mmap->center.y = mmap->center.y;
	dot.origin.x = mmap->center.x + player->dir.x * (mmap->tile_size - 2);
	dot.origin.y = mmap->center.y + player->dir.y * (mmap->tile_size - 2);
	render_circle(&dot);
}

void	minimap_render(void)
{
	t_window	*window;
	t_minimap	mmap;

	window = _window();
	window->enable_transparency = TRUE;
	minimap_setup(&mmap);
	minimap_render_colliders(&mmap);
	minimap_render_player(&mmap);
	minimap_render_direction(&mmap);
	window->enable_transparency = FALSE;
}
