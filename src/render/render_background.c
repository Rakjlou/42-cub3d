/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/12 01:34:18 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/render.h"
#include "render/window.h"
#include "map/map.h"
#include "game.h"
#include "mlx.h"

void	render_background(void)
{
	int			line;
	int			column;
	t_color		*ceiling;
	t_color		*floor;

	line = 0;
	ceiling = &_map()->color_ceiling;
	floor = &_map()->color_floor;
	while (line < WINDOW_HEIGHT)
	{
		column = 0;
		while (column < WINDOW_WIDTH)
		{
			if (line < WINDOW_HEIGHT / 2)
				window_set_pixel(line, column, ceiling);
			else
				window_set_pixel(line, column, floor);
			++column;
		}
		++line;
	}
}
