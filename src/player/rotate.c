/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/12 15:53:54 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include <math.h>

static void	player_rotate(double rot_speed)
{
	double		old_dir_x;
	double		old_fov_x;
	t_player	*player;
	t_dvector	*dir;
	t_dvector	*fov;

	player = _player();
	dir = &player->dir;
	fov = &player->fov;
	old_dir_x = dir->x;
	old_fov_x = fov->x;
	dir->x = dir->x * cos(rot_speed) - dir->y * sin(rot_speed);
	dir->y = old_dir_x * sin(rot_speed) + player->dir.y * cos(rot_speed);
	fov->x = fov->x * cos(rot_speed) - fov->y * sin(rot_speed);
	fov->y = old_fov_x * sin(rot_speed) + fov->y * cos(rot_speed);
}

void	player_rotate_left(void)
{
	player_rotate(_player()->rotation_speed);
}

void	player_rotate_right(void)
{
	player_rotate(-_player()->rotation_speed);
}
