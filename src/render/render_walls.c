/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/12 18:53:26 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "render/window.h"
#include "map/map.h"
#include "mlx.h"

static void	render_pixel_column(t_wall *wall)
{
	t_color	color[WALL_CARDINAL_TOTAL];
	t_map	*map;
	int		line;

	line = 0;
	map = _map();
	color[WALL_NORTH] = 0x00632626;
	color[WALL_SOUTH] = 0x009D5353;
	color[WALL_EAST] = 0x00BF8B67;
	color[WALL_WEST] = 0x00DACC96;
	while (line <= WINDOW_HEIGHT)
	{
		if (line < wall->draw_start)
			window_set_pixel(line, wall->column, map->color_ceiling);
		else if (line >= wall->draw_start && line <= wall->draw_end)
			window_set_pixel(line, wall->column, color[wall->cardinal]);
		else
			window_set_pixel(line, wall->column, map->color_floor);
		line++;
	}
}

void	render_walls(void)
{
	t_wall	wall;
	int		column;

	column = 0;
	while (column < WINDOW_WIDTH)
	{
		raycast_wall_from_wcolumn(&wall, column);
		render_pixel_column(&wall);
		++column;
	}
}
