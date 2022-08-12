/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/12 14:37:40 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "render/window.h"
#include "map/map.h"
#include "mlx.h"

static void	render_wall(t_wall *wall)
{
	t_map	*map;
	int		line;

	line = 0;
	map = _map();
	while (line <= WINDOW_HEIGHT)
	{
		if (line < wall->draw_start)
			window_set_pixel(line, wall->column, map->color_ceiling);
		else if (line >= wall->draw_start && line <= wall->draw_end)
			window_set_pixel(line, wall->column, 0x00435560);
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
		render_wall(&wall);
		++column;
	}
}
