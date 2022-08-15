/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_callback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/14 18:44:45 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/window.h"
#include "errors.h"
#include "game.h"
#include "mlx.h"

void	window_set_mouse_click_callback(int (*callback)(int, int, int))
{
	mlx_mouse_hook(_window()->core, callback, NULL);
}

void	window_set_mouse_move_callback(int (*callback)(int, int))
{
	mlx_hook(_window()->core, 6, 0x40, callback, NULL);
}

void	window_set_expose_callback(int (*callback)(void))
{
	mlx_expose_hook(_window()->core, callback, NULL);
}

void	window_set_close_callback(int (*callback)(void))
{
	mlx_hook(_window()->core, 17, 0, callback, NULL);
}

void	window_set_loop_callback(int (*callback)(void))
{
	mlx_loop_hook(_window()->mlx, callback, NULL);
}
