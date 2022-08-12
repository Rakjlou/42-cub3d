/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/12 11:59:36 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/window.h"
#include "raycasting.h"
#include "player.h"
#include "libft.h"
#include <math.h>

void	ray_init(t_ray *ray, int column)
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
