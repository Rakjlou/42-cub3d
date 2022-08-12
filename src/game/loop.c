/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/11 23:36:10 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/window.h"
#include "render/render.h"
#include "map/map.h"
#include "mlx.h"
#include "ftprintf.h"
#include "input.h"
#include "player.h"
#include "raycasting.h"
#include <math.h>
#include <float.h>

/*
void	compute_side_distance(t_info info)
{
	t_dda	*dda;

	dda = _dda();
	if (dda->rayDirX < 0)
	{
		dda->stepX = -1;
		dda->sideDistX = (info.posX - dda->mapX) * dda->deltaDistX;
	}
	else
	{
		dda->stepX = 1;
		dda->sideDistX = (dda->mapX + 1.0 - info.posX) * dda->deltaDistX;
	}
	if (dda->rayDirY < 0)
	{
		dda->stepY = -1;
		dda->sideDistY = (info.posY - dda->mapY) * dda->deltaDistY;
	}
	else
	{
		dda->stepY = 1;
		dda->sideDistY = (dda->mapY + 1.0 - info.posY) * dda->deltaDistY;
	}
}

void	compute_wall_distance(t_info info)
{
	t_dda	*dda;

	dda = _dda();
	if (dda->side == 0)
		dda->perpWallDist = (dda->mapX - info.posX + (1 - dda->stepX) / 2) / dda->rayDirX;
	else
		dda->perpWallDist = (dda->mapY - info.posY + (1 - dda->stepY) / 2) / dda->rayDirY;
	dda->lineHeight = (int)(height / dda->perpWallDist);
	dda->drawStart = -dda->lineHeight / 2 + height / 2;
	if (dda->drawStart < 0)
		dda->drawStart = 0;
	dda->drawEnd = dda->lineHeight / 2 + height / 2;
	if (dda->drawEnd >= height)
		dda->drawEnd = height - 1;
}
void	init_dda_parameter(t_info info, int x)
{
	t_dda	*dda;

	dda = _dda();
	dda->hit = 0;
	dda->cameraX = 2 * x / (double)width - 1;
	dda->rayDirX = info.dirX + info.planeX * dda->cameraX;
	dda->rayDirY = info.dirY + info.planeY * dda->cameraX;
	dda->mapX = (int)info.posX;
	dda->mapY = (int)info.posY;
	dda->deltaDistX = fabs(1 / dda->rayDirX);
	dda->deltaDistY = fabs(1 / dda->rayDirY);
}

void color_wall(void)
{
	t_dda	*dda;

	dda = _dda();
	if (worldMap[dda->mapY][dda->mapX] == 1)
		dda->color = 0xFF0000;
	else if (worldMap[dda->mapY][dda->mapX] == 2)
		dda->color = 0x00FF00;
	else if (worldMap[dda->mapY][dda->mapX] == 3)
		dda->color = 0x0000FF;
	else if (worldMap[dda->mapY][dda->mapX] == 4)
		dda->color = 0xFFFFFF;
	else
		dda->color = 0xFFFF00;

	if (dda->side == 1)
		dda->color = dda->color / 2;
}

void	verLine(int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		img_pxl_put(x, y, color);
		y++;
	}
}


static void	compute_raycasting(void)
{
	t_info *info;
	t_dda	*d;
	int	x;

	info = _mlx_data();
	d = _dda();
	x = 0;
	while (x < width)
	{
		init_dda_parameter(*info, x);
		compute_side_distance(*info);
		check_hit(*info);
		compute_wall_distance(*info);
		color_wall();
		verLine(x, d->drawStart, d->drawEnd, d->color);
		x++;
	}
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
	ray->delta_dist.x = DBL_MAX;
	ray->delta_dist.y = DBL_MAX;
	if (ray->dir.x != 0)
		ray->delta_dist.x = fabs(1 / ray->dir.x);
	if (ray->dir.y != 0)
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
	wall->line_height = WINDOW_HEIGHT / ray->length;
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
	int	line;

	line = wall->draw_start;
	while (line <= wall->draw_end)
	{
		window_set_pixel(line, wall->column, 0xFF0000);
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
	render_background();
	render_walls();
	window_refresh();
	ftfprintf(STDERR_FILENO, "END\n");
	return (0);
}

void	game_loop(void)
{
	mlx_loop(_window()->mlx);
}
