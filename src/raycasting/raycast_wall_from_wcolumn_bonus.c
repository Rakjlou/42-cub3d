/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_wall_from_wcolumn_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/24 10:47:59 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/window.h"
#include "raycasting.h"
#include "libft.h"

#include "map/map.h"
#include "render/texture.h"
#include "player.h"
#include <math.h>

#include <stdio.h>

static void	wall_hydrate_texture(t_wall *wall)
{
	t_map		*map;
	t_tile		*tile;
	t_texture	*texture[WALL_CARDINAL_TOTAL];

	map = _map();
	texture[WALL_NORTH] = &map->texture_north;
	texture[WALL_SOUTH] = &map->texture_south;
	texture[WALL_EAST] = &map->texture_east;
	texture[WALL_WEST] = &map->texture_west;
	wall->texture = texture[wall->cardinal];
	tile = map_get_tile(wall->ray.tile.x, wall->ray.tile.y);
	if (wall->ray.length < 1.0 && wall->cardinal == WALL_NORTH)
		wall->texture = texture[WALL_EAST];
	else if (tile != NULL && tile->type == 'D')
		wall->texture = texture[WALL_NORTH];
}

static void	compute_wall_texture(t_wall *wall, t_ray *ray)
{
	t_player	*player;
	double		wall_col;

	player = _player();
	wall_col = player->pos.y + ray->length * ray->dir.y;
	if (ray->side != 0)
		wall_col = player->pos.x + ray->length * ray->dir.x;
	wall_col -= floor(wall_col);
	wall_hydrate_texture(wall);
	wall->texture_column = (int)(wall_col * (double)wall->texture->width);
	wall->texture_step = 1.0 * wall->texture->height / wall->line_height;
	wall->tex_pos = (wall->draw_start - WINDOW_HEIGHT / 2
			+ wall->line_height / 2) * wall->texture_step;
}

static void	compute_wall(t_wall *wall, t_ray *ray, int column)
{
	wall->column = column;
	wall->line_height = (int)(WINDOW_HEIGHT / ray->length);
	wall->draw_start = -wall->line_height / 2 + WINDOW_HEIGHT / 2;
	if (wall->draw_start < 0)
		wall->draw_start = 0;
	wall->draw_end = wall->line_height / 2 + WINDOW_HEIGHT / 2;
	if (wall->draw_end >= WINDOW_HEIGHT)
		wall->draw_end = WINDOW_HEIGHT - 1;
	if (ray->side == 0 && ray->step_dir.x == -1)
		wall->cardinal = WALL_NORTH;
	else if (ray->side == 0 && ray->step_dir.x == 1)
		wall->cardinal = WALL_SOUTH;
	if (ray->side == 1 && ray->step_dir.y == 1)
		wall->cardinal = WALL_EAST;
	else if (ray->side == 1 && ray->step_dir.y == -1)
		wall->cardinal = WALL_WEST;
	compute_wall_texture(wall, ray);
}

void	raycast_wall_from_wcolumn(t_wall *wall, int column)
{
	t_ray	ray;

	ray_init(&ray, column);
	ray_compute_side_dist(&ray);
	ray_hit(&ray);
	ray_compute_length(&ray);
	ft_memcpy(&wall->ray, &ray, sizeof(t_ray));
	compute_wall(wall, &ray, column);
}
