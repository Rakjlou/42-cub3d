/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/22 22:31:57 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "render/window.h"
#include "map/map.h"
#include "mlx.h"

static t_bool	load_wall_textures(void)
{
	t_map		*map;

	map = _map();
	return (
		texture_hydrate(&map->texture_north)
		&& texture_hydrate(&map->texture_south)
		&& texture_hydrate(&map->texture_east)
		&& texture_hydrate(&map->texture_west)
	);
}

t_bool	window_init(void)
{
	t_window	*window;

	window = _window();
	window->mlx = mlx_init();
	if (window->mlx == NULL)
		return (fterr_set_error(E_MLX_FAILURE), FALSE);
	window->core = mlx_new_window(
			window->mlx,
			WINDOW_HEIGHT, WINDOW_WIDTH, WINDOW_TITLE);
	if (window->core == NULL)
		return (fterr_set_error(E_MLX_FAILURE), FALSE);
	return (load_wall_textures());
}
