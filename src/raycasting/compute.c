/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/12 12:03:29 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "player.h"

void	ray_compute_side_dist(t_ray *r)
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

void	ray_compute_length(t_ray *ray)
{
	if (ray->side == 0)
		ray->length = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->length = ray->side_dist.y - ray->delta_dist.y;
}
