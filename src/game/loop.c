/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/12 11:45:33 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/window.h"
#include "map/map.h"
#include "mlx.h"
#include "ftprintf.h"
#include "input.h"
#include "player.h"
#include "raycasting.h"
#include <math.h>
#include <float.h>
#include <stdio.h>
/*
void	ray_debug(t_ray *ray)
{
	dprintf(STDERR_FILENO, "vvv RAY DEBUG vvv\n");
	dprintf(STDERR_FILENO, "hit:        %d\n", ray->hit);
	dprintf(STDERR_FILENO, "dir:        %f / %f\n", ray->dir.x, ray->dir.y);
	dprintf(STDERR_FILENO, "delta_dist: %f / %f\n",
			ray->delta_dist.x, ray->delta_dist.y);
	dprintf(STDERR_FILENO, "side_dist:  %f / %f\n",
			ray->side_dist.x, ray->side_dist.y);
	dprintf(STDERR_FILENO, "step_dir:   %d / %d\n",
			ray->step_dir.x, ray->step_dir.y);
	dprintf(STDERR_FILENO, "tile:       %d / %d\n", ray->tile.x, ray->tile.y);
	dprintf(STDERR_FILENO, "camera_x:   %f\n", ray->camera_x);
	dprintf(STDERR_FILENO, "length:     %f\n", ray->length);
	dprintf(STDERR_FILENO, "side:       %d\n", ray->side);
	dprintf(STDERR_FILENO, "^^^ RAY DEBUG ^^^\n");
}

void	wall_debug(t_wall *wall)
{
	dprintf(STDERR_FILENO, "vvv WALL DEBUG vvv\n");
	dprintf(STDERR_FILENO, "column:      %d\n", wall->column);
	dprintf(STDERR_FILENO, "line_height: %d\n", wall->line_height);
	dprintf(STDERR_FILENO, "draw_start:  %d\n", wall->draw_start);
	dprintf(STDERR_FILENO, "draw_end:    %d\n", wall->draw_end);
	dprintf(STDERR_FILENO, "^^^ WALL DEBUG ^^^\n");
}
*/
static void	ray_init(t_ray *ray, int column)
{
	t_player	*player;

	player = _player();
	ft_bzero(ray, sizeof(t_ray));
	ray->tile.x = (int)player->pos.x;
	ray->tile.y = (int)player->pos.y;
	ray->camera_x = 2 * column / (double)WINDOW_WIDTH - 1;
	ray->dir.x = player->dir.x + player->fov.x * ray->camera_x;
	ray->dir.y = player->dir.y + player->fov.y * ray->camera_x;
	ray->delta_dist.x = fabs(1 / ray->dir.x);
	ray->delta_dist.y = fabs(1 / ray->dir.y);
}

static void	compute_side_distance(t_ray *r)
{
	t_player	*player;

	player = _player();
	if (r->dir.x < 0)
	{
		r->step_dir.x = -1;
		r->side_dist.x = (player->pos.x - r->tile.x) * r->delta_dist.x;
	}
	else
	{
		r->step_dir.x = 1;
		r->side_dist.x = (r->tile.x + 1.0 - player->pos.x) * r->delta_dist.x;
	}
	if (r->dir.y < 0)
	{
		r->step_dir.y = -1;
		r->side_dist.y = (player->pos.y - r->tile.y) * r->delta_dist.y;
	}
	else
	{
		r->step_dir.y = 1;
		r->side_dist.y = (r->tile.y + 1.0 - player->pos.y) * r->delta_dist.y;
	}
}

static void	hit(t_ray *ray)
{
	ray->hit = FALSE;
	while (ray->hit == FALSE)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->tile.x += ray->step_dir.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->tile.y += ray->step_dir.y;
			ray->side = 1;
		}
		if (tile_collides_by_pos(ray->tile.x, ray->tile.y) > 0)
			ray->hit = TRUE;
	}
}

static void	compute_length(t_ray *ray)
{
	if (ray->side == 0)
		ray->length = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->length = ray->side_dist.y - ray->delta_dist.y;
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
}

/* ADL ??? */
static void	color_wall(t_wall *wall)
{
	(void)wall;
}

static void	render_wall(t_wall *wall)
{
	t_map	*map;
	int		line;

	line = 0;
	map = _map();
	while (line <= WINDOW_HEIGHT)
	{
		if (line < wall->draw_start)
			window_set_pixel(line, wall->column, map->color_ceiling);
		else if (line >= wall->draw_start && line <= wall->draw_end)
			window_set_pixel(line, wall->column, 0x00FF0000);
		else
			window_set_pixel(line, wall->column, map->color_floor);
		line++;
	}
}

static void	render_walls(void)
{
	t_ray	ray;
	t_wall	wall;
	int		column;

	column = 0;
	while (column < WINDOW_WIDTH)
	{
		ray_init(&ray, column);
		compute_side_distance(&ray);
		hit(&ray);
		compute_length(&ray);
		compute_wall(&wall, &ray, column);
		color_wall(&wall);
		render_wall(&wall);
		++column;
	}
}

int	game_loop_callback(void)
{
	ftfprintf(STDERR_FILENO, "BEG\n");
	render_walls();
	window_refresh();
	ftfprintf(STDERR_FILENO, "END\n");
	return (0);
}

void	game_loop(void)
{
	mlx_loop(_window()->mlx);
}
