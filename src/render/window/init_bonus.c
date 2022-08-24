/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/24 11:11:47 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "render/window.h"
#include "map/map.h"
#include "mlx.h"

static t_bool	set_door_texture(void)
{
	t_map		*map;

	map = _map();
	map->texture_door.filename = ft_strdup("./resource/door.xpm");
	if (map->texture_door.filename == NULL)
		return (FALSE);
	return (texture_hydrate(&map->texture_door));
}

static t_bool	load_wall_textures(void)
{
	t_map		*map;

	map = _map();
	return (
		texture_hydrate(&map->texture_north)
		&& texture_hydrate(&map->texture_south)
		&& texture_hydrate(&map->texture_east)
		&& texture_hydrate(&map->texture_west)
		&& set_door_texture()
	);
}

static t_bool	generate_buffer(void)
{
	t_window	*win;

	win = _window();
	win->buffer_image = mlx_new_image(win->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (win->buffer_image == NULL)
		return (fterr_set_error(E_MLX_FAILURE), FALSE);
	win->buffer = mlx_get_data_addr(
			win->buffer_image,
			&win->depth, &win->line_size, &win->endian);
	return (TRUE);
}

t_bool	window_init(void)
{
	t_window	*win;

	win = _window();
	win->mlx = mlx_init();
	if (win->mlx == NULL)
		return (fterr_set_error(E_MLX_FAILURE), FALSE);
	win->core = mlx_new_window(
			win->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	if (win->core == NULL)
		return (fterr_set_error(E_MLX_FAILURE), FALSE);
	win->center.x = WINDOW_HEIGHT / 2;
	win->center.y = WINDOW_WIDTH / 2;
	mlx_mouse_move(win->mlx, win->core, win->center.y, win->center.x);
	return (load_wall_textures() && generate_buffer());
}
