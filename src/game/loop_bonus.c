/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/24 10:54:29 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/render.h"
#include "render/window.h"
#include "map/minimap.h"
#include "player.h"
#include "mlx.h"

#include "map/map.h"

int	game_loop_callback(void)
{
	player_update();
	render_colliders();
	minimap_render();
	window_refresh();
	return (0);
}

void	game_loop(void)
{
	mlx_loop(_window()->mlx);
}
