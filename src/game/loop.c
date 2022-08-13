/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/13 19:13:30 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/render.h"
#include "render/window.h"
#include "player.h"
#include "mlx.h"

#include "vectors.h"
#include "render/rect.h"
#include "render/circle.h"
#include "libft.h"
#include "map/map.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*	RR = SR × SA + DR × (1 − SA)
    RG = SG × SA + DG × (1 − SA)
    RB = SB × SA + DB × (1 − SA)*/
/*	t_color_channels	s;
	t_color_channels	d;

	color_channels(source, &s);
	color_channels(dest, &d);
	return (
		color_build(
			s.r * s.a + d.r * (1 - s.a),
			s.g * s.a + d.g * (1 - s.a),
			s.b * s.a + d.b * (1 - s.a),
			0
		)
	);*/

void	rect_set_pixel(t_rect *rect, int line, int column, t_color color)
{
	if (line < 0 || line > WINDOW_HEIGHT
		|| line < rect->start.x || line > rect->end.x
		|| column < rect->start.y || column > rect->end.y)
		return ;
	window_set_pixel(line, column, color);
}

static void	rect_draw_grid(t_rect *rect, int line, int column)
{
	t_ivector	point;

	point.x = line - rect->start.x;
	point.y = column - rect->start.y;
	if ((point.x + rect->grid_offset.x) % rect->cell_size == 0
		|| (point.y + rect->grid_offset.y) % rect->cell_size == 0)
		rect_set_pixel(rect, line, column, rect->grid_color);
	else
		rect_set_pixel(rect, line, column, rect->fill_color);
}

void	rect_render(t_rect *rect)
{
	int	line;
	int	column;

	line = rect->start.x;
	while (line <= rect->end.x)
	{
		column = rect->start.y;
		while (column <= rect->end.y)
		{
			if (line == rect->start.x || line == rect->end.x)
				rect_set_pixel(rect, line, column, rect->border_color);
			else if (column == rect->start.y || column == rect->end.y)
				rect_set_pixel(rect, line, column, rect->border_color);
			else if (rect->cell_size > 0)
				rect_draw_grid(rect, line, column);
			else
				rect_set_pixel(rect, line, column, rect->fill_color);
			++column;
		}
		++line;
	}
}

void	render_circle(t_circle *circle)
{
	t_rect	rect;
	int		line;
	int		column;
	int		in_point;

	rect.start.x = circle->origin.x - circle->radius;
	rect.start.y = circle->origin.y - circle->radius;
	rect.end.x = circle->origin.x + circle->radius;
	rect.end.y = circle->origin.y + circle->radius;
	line = rect.start.x;
	while (line <= rect.end.x)
	{
		column = rect.start.y;
		while (column <= rect.end.y)
		{
			in_point = (line - circle->origin.x) * (line - circle->origin.x)
				+ (column - circle->origin.y) * (column - circle->origin.y)
				<= circle->radius * circle ->radius;
			if (in_point)
				rect_set_pixel(&rect, line, column, circle->fill_color);
			++column;
		}
		++line;
	}
}

void	rect_center(t_rect *rect, t_ivector *result)
{
	result->x = rect->start.x + ((rect->end.x - rect->start.x) / 2);
	result->y = rect->start.y + ((rect->end.y - rect->start.y) / 2);
}

void	minimap_render_grid(t_rect *zone)
{
	t_player	*player;
	t_rect		grid;

	player = _player();
	grid.start.x = zone->start.x;
	grid.start.y = zone->start.y;
	grid.end.x = zone->end.x;
	grid.end.y = zone->end.y;
	grid.fill_color = 0xFF000000;
	grid.border_color = 0xFF000000;
	grid.cell_size = (int)(ft_min(WINDOW_WIDTH, WINDOW_HEIGHT) * 0.25)
		/ player->minimap_sight;
	grid.grid_color = 0x00FFFFFF;
	grid.grid_offset.x = -grid.cell_size * ((int)player->pos.x - player->pos.x);
	grid.grid_offset.y = -grid.cell_size * ((int)player->pos.y - player->pos.y);
	rect_render(&grid);
}

static void	minimap_render_background(t_rect *zone)
{
	int			size;

	size = (int)(ft_min(WINDOW_WIDTH, WINDOW_HEIGHT) * 0.25);
	zone->start.x = 10;
	zone->start.y = WINDOW_WIDTH - size - 10;
	zone->end.x = zone->start.x + size;
	zone->end.y = zone->start.y + size;
	zone->fill_color = 0xFFFFFFFF;
	zone->border_color = 0xFFFFFFFF;
	zone->cell_size = 0;
	/*rect_render(zone);*/
	/*minimap_render_grid(zone);*/
}

static void	minimap_render_collider(
	t_rect *zone,
	int line,
	int column,
	int cell_size)
{
	t_rect	collider;

	collider.start.x = zone->start.x + cell_size * line;
	collider.start.y = zone->start.y + cell_size * column;
	collider.end.x = collider.start.x + cell_size;
	collider.end.y = collider.start.y + cell_size;
	collider.fill_color = 0x7FFFFFFF;
	collider.border_color = 0xFFFF0000;
	collider.cell_size = 0;
	rect_render(&collider);
}

static void	minimap_render_walls(t_rect *zone)
{
	int			line;
	int			column;
	int			cell_size;
	t_ivector	index;
	t_player	*player;

	(void)zone;
	player = _player();
	line = (int)player->pos.x - player->minimap_sight;
	index.x = 0;
	cell_size = (zone->end.x - zone->start.x) / (player->minimap_sight * 2 + 1);
	while (line <= (int)player->pos.x + player->minimap_sight)
	{
		column = (int)player->pos.y - player->minimap_sight;
		index.y = 0;
		while (column <= (int)player->pos.y + player->minimap_sight)
		{
			if (tile_collides_by_pos(line, column))
				minimap_render_collider(zone, index.x, index.y, cell_size);
			printf("[%3d %3d]", line, column);
			++column;
			++index.y;
		}
		printf("\n");
		++line;
		++index.x;
	}
	printf("------------------\n");
/*	t_dvector	relative;
	t_ivector	mmap_len;
	t_ivector	mmap;
	t_ivector	tile;

	mmap.x = 1;
	mmap_len.x = zone->end.x - zone->start.x;
	mmap_len.y = zone->end.y - zone->start.y;
	while (mmap.x + zone->start.x < zone->end.x)
	{
		mmap.y = 1;
		while (mmap.y + zone->start.y < zone->end.y)
		{
			relative.x = (double)(((mmap.x * 100.0) / mmap_len.x) / 100.0);
			relative.y = (double)(((mmap.y * 100.0) / mmap_len.y) / 100.0);
			tile.x = (relative.x * 100) /_map()->width;
			tile.y = (relative.y * 100) /_map()->height;
			printf("LEN %d %d\n", mmap_len.x, mmap_len.y);
			printf(">>> %f %f\n", relative.x, relative.y);
			printf("<<< %d %d\n", tile.x, tile.y);
			++mmap.y;
		}
		++mmap.x;
	}*/
}

static void	minimap_render_dot(t_rect *zone)
{
	t_circle	dot;

	rect_center(zone, &dot.origin);
	dot.radius = 2;
	dot.fill_color = 0xC8F87CA;
	dot.border_color = 0xC8F87CA;
	render_circle(&dot);
}

static void	minimap_render(void)
{
	t_window	*window;
	t_rect		zone;

	window = _window();
	window->enable_transparency = TRUE;
	minimap_render_background(&zone);
	minimap_render_walls(&zone);
	minimap_render_dot(&zone);
	window->enable_transparency = FALSE;
}

static void	game_update(void)
{
	player_update();
}

int	game_loop_callback(void)
{
	game_update();
	render_walls(); /* ??? RENAME ??? */
	minimap_render();
	window_refresh();
	return (0);
}

void	game_loop(void)
{
	mlx_loop(_window()->mlx);
}
