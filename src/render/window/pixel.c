/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/12 19:23:39 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/window.h"
#include "mlx.h"
#include <stdlib.h>

static t_color	alpha_blend(t_color background, t_color foreground)
{
	unsigned int		alpha;
	unsigned int		inv_alpha;
	t_color_channels	bg;
	t_color_channels	fg;

	color_channels(background, &bg);
	color_channels(foreground, &fg);
	alpha = 256 - fg.a;
	inv_alpha = fg.a + 1;
	return (color_build((unsigned char)((alpha * fg.r + inv_alpha * bg.r) >> 8),
		(unsigned char)((alpha * fg.g + inv_alpha * bg.g) >> 8),
		(unsigned char)((alpha * fg.b + inv_alpha * bg.b) >> 8),
		0
	));
}

void	window_set_pixel(int line, int column, t_color color)
{
	static t_window	*window = NULL;
	t_color			*pixel;

	if (window == NULL)
		window = _window();
	pixel = window_get_pixel(line, column);
	if (pixel != NULL)
	{
		if (window->enable_transparency == TRUE)
			*pixel = alpha_blend(*pixel, color);
		else
			*pixel = color;
	}
}

t_color	*window_get_pixel(int line, int column)
{
	t_window	*window;
	int			*pixel;
	int			index;
	int			max;

	window = _window();
	index = line * window->line_size + column * sizeof(int);
	max = WINDOW_HEIGHT * window->line_size + WINDOW_WIDTH * sizeof(int);
	pixel = (int *)(window->buffer + index);
	if (index < max)
		return (pixel);
	return (NULL);
}
