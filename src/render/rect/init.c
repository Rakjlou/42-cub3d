/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/13 20:11:43 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/rect.h"

void	rect_size_init(t_rect *rect)
{
	rect->size.x = rect->end.x - rect->start.x;
	rect->size.y = rect->end.y - rect->start.y;
}

void	rect_start_init(t_rect *rect, int start_x, int start_y)
{
	rect->start.x = start_x;
	rect->start.y = start_y;
}

void	rect_end_init(t_rect *rect, int end_x, int end_y)
{
	rect->end.x = end_x;
	rect->end.y = end_y;
}

void	rect_square_init(t_rect *rect, int start_x, int start_y, int size)
{
	rect_start_init(rect, start_x, start_y);
	rect_end_init(rect, rect->start.x + size, rect->start.y + size);
	rect_size_init(rect);
}

void	rect_color_init(t_rect *rect, t_color fill_color, t_color border_color)
{
	rect->fill_color = fill_color;
	rect->border_color = border_color;
}
