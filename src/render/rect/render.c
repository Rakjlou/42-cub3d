/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/13 20:29:13 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/rect.h"
#include "render/window.h"

void	rect_render_pixel(t_rect *rect, int line, int column, t_color color)
{
	if (line < 0 || line > WINDOW_HEIGHT
		|| line < rect->start.x || line > rect->end.x
		|| column < rect->start.y || column > rect->end.y)
		return ;
	window_set_pixel(line, column, color);
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
				rect_render_pixel(rect, line, column, rect->border_color);
			else if (column == rect->start.y || column == rect->end.y)
				rect_render_pixel(rect, line, column, rect->border_color);
			else
				rect_render_pixel(rect, line, column, rect->fill_color);
			++column;
		}
		++line;
	}
}
