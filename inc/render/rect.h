/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:26:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/13 20:44:14 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECT_H
# define RECT_H

# include "vectors.h"
# include "render/color.h"

typedef struct s_rect
{
	t_ivector		start;
	t_ivector		end;
	t_ivector		size;
	t_color			border_color;
	t_color			fill_color;
}	t_rect;

void	rect_start_init(t_rect *rect, int start_x, int start_y);
void	rect_end_init(t_rect *rect, int end_x, int end_y);
void	rect_size_init(t_rect *rect);
void	rect_square_init(t_rect *rect, int start_x, int start_y, int size);
void	rect_color_init(t_rect *rect, t_color fill_color, t_color border_color);

void	rect_get_center(t_rect *rect, t_ivector *result);

void	rect_render(t_rect *rect);
void	rect_render_in_rect(t_rect *parent, t_rect *to_draw);
void	rect_render_pixel(t_rect *rect, int line, int column, t_color color);

#endif
