/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/13 20:32:26 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/circle.h"
#include "render/rect.h"

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
				rect_render_pixel(&rect, line, column, circle->fill_color);
			++column;
		}
		++line;
	}
}
