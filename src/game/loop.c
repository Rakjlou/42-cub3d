/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/12 16:03:22 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/render.h"
#include "render/window.h"
#include "mlx.h"

#include "map/map_tile.h"
#include "input.h"
#include "player.h"
#include "ftprintf.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static void	game_update(void)
{
	player_update();
}

int	game_loop_callback(void)
{
	game_update();
	render_walls();
	window_refresh();
	return (0);
}

void	game_loop(void)
{
	mlx_loop(_window()->mlx);
}
