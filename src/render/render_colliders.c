/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_colliders.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/15 21:54:55 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "render/window.h"
#include "map/map.h"
#include "mlx.h"

#include <stdio.h>

static void	render_pixel_column(t_wall *wall)
{
	t_map	*map;
	t_color	*to_draw;
	int		line;
	int		tex_line;

	line = 0;
	map = _map();
	while (line <= WINDOW_HEIGHT)
	{
		if (line < wall->draw_start)
			window_set_pixel(line, wall->column, map->color_ceiling);
		else if (line >= wall->draw_start && line <= wall->draw_end)
		{
			tex_line = (int)wall->tex_pos & (wall->texture->height - 1);
			to_draw = texture_get_pixel(wall->texture,
					tex_line, wall->texture_column);
			if (to_draw != NULL)
				window_set_pixel(line, wall->column, *to_draw);
			wall->tex_pos += wall->texture_step;
		}
		else
			window_set_pixel(line, wall->column, map->color_floor);
		++line;
	}
}

void	render_colliders(void)
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
