/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_wall_from_wcolumn.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/12 15:40:16 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/window.h"
#include "raycasting.h"
#include <stdio.h>

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
}

void	raycast_wall_from_wcolumn(t_wall *wall, int column)
{
	t_ray	ray;

	ray_init(&ray, column);
	ray_compute_side_dist(&ray);
	ray_hit(&ray);
	ray_compute_length(&ray);
	compute_wall(wall, &ray, column);
}
