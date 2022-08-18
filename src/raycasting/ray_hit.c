/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/18 21:20:26 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "map/map_tile.h"

#include "map/map.h"
#include "player.h"
#include <stdio.h>
#include <math.h>

void	ray_hit(t_ray *ray)
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
		if (tile_collides_by_pos(ray->tile.x, ray->tile.y))
		{
			if (map_get_tile(ray->tile.x, ray->tile.y)->type == 'D')
					ray->hit = TRUE;
			else
				ray->hit = TRUE;
		}
	}
}
