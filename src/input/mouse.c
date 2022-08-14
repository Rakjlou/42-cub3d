/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/14 19:11:17 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/window.h"
#include "vectors.h"
#include "mlx.h"

void	input_get_mouse_pos(t_ivector *pos)
{
	t_window	*window;

	window = _window();
	mlx_mouse_get_pos(window->mlx, window->core, &pos->y, &pos->x);
}

void	input_mouse_move(int pos_x, int pos_y)
{
	t_window	*window;

	window = _window();
	mlx_mouse_move(window->mlx, window->core, pos_y, pos_x);
}
