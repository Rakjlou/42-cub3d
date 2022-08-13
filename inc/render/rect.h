/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:26:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/12 20:40:52 by nsierra-         ###   ########.fr       */
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
	t_ivector		grid_offset;
	t_color			border_color;
	t_color			fill_color;
	t_color			grid_color;
	int				cell_size;
}	t_rect;

void	rect_render(t_rect *rect);
void	rect_center(t_rect *rect, t_ivector *result);

#endif
