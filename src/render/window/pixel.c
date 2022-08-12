/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/12 18:21:32 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/window.h"
#include "mlx.h"
#include <stdlib.h>

void	window_set_pixel(int line, int column, t_color color)
{
	t_color		*pixel;

	pixel = window_get_pixel(line, column);
	if (pixel != NULL)
		*pixel = color;
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
