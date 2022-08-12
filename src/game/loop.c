/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/12 19:02:45 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/render.h"
#include "render/window.h"
#include "player.h"
#include "mlx.h"

#include "vectors.h"
#include "render/rect.h"
#include "libft.h"
#include "map/map.h"
#include <stdio.h>

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
static t_color	alpha_blend(t_color background, t_color foreground)
{
	unsigned int		alpha;
	unsigned int		inv_alpha;
	t_color_channels	bg;
	t_color_channels	fg;

	color_channels(background, &bg);
	color_channels(foreground, &fg);
/*	printf("%3x %3x %3x %3x %x\n", bg.a, bg.r, bg.g, bg.b, background);
	printf("%3x %3x %3x %3x %x\n", fg.a, fg.r, fg.g, fg.b, foreground);
	printf("----\n");*/
	alpha = 256 - fg.a;
	inv_alpha = fg.a + 1;
	return (
		color_build(
			(unsigned char)((alpha * fg.r + inv_alpha * bg.r) >> 8),
			(unsigned char)((alpha * fg.g + inv_alpha * bg.g) >> 8),
			(unsigned char)((alpha * fg.b + inv_alpha * bg.b) >> 8),
			0xff
		)
	);
}

void	rect_set_pixel(t_rect *rect, int line, int column, t_color color)
{
	t_color	background;

	if (line < 0 || line > WINDOW_HEIGHT
		|| line < rect->start.x || line > rect->end.x
		|| column < rect->start.y || column > rect->end.y)
		return ;
	background = *window_get_pixel(line, column);
	window_set_pixel(line, column, alpha_blend(background, color));
}

void	render_rect(t_rect *rect)
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
			else
				rect_set_pixel(rect, line, column, rect->fill_color);
			++column;
		}
		++line;
	}
}

static void	render_minimap(void)
{
	int		size;
	t_rect	zone;

	size = (int)(ft_min(WINDOW_WIDTH, WINDOW_HEIGHT) * 0.25);
	zone.start.x = 10;
	zone.start.y = WINDOW_WIDTH - size - 10;
	zone.end.x = zone.start.x + size;
	zone.end.y = zone.start.y + size;
	zone.fill_color = 0x7FFFFFFF;
	render_rect(&zone);
}

static void	game_update(void)
{
	player_update();
}

int	game_loop_callback(void)
{
	game_update();
	render_walls();
	render_minimap();
	window_refresh();
	return (0);
}

void	game_loop(void)
{
	mlx_loop(_window()->mlx);
}
