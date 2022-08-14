/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/14 19:38:58 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/window.h"
#include "player.h"
#include "input.h"

#include <stdio.h>
#include <math.h>

static void	update_movement(void)
{
	t_input	*input;

	input = _input();
	if (input->forward && !input->backward)
		player_move_forward();
	if (input->backward && !input->forward)
		player_move_backward();
	if (input->left && !input->right)
		player_move_left();
	if (input->right && !input->left)
		player_move_right();
	if (input->rotate_left && !input->rotate_right)
		player_rotate_left();
	if (input->rotate_right && !input->rotate_left)
		player_rotate_right();
}

static void	player_rotate_test(double rot_speed)
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

static void	update_mouse_movement(void)
{
	t_player	*player;
	t_ivector	mouse;
	int			rotation;
	int			i;
	int			sign;

	player = _player();
	input_get_mouse_pos(&mouse);
	rotation = mouse.y - _window()->center.y;
	input_mouse_move(_window()->center.x, _window()->center.y);
	i = 0;
	sign = 1;
	if (rotation < 0)
	{
		rotation = -rotation;
		sign = -1;
	}
	while (i < rotation)
	{
		if (sign < 0)
			player_rotate_test(player->rotation_speed);
		else
			player_rotate_test(-player->rotation_speed);
		++i;
	}
}

void	player_update(void)
{
	update_movement();
	update_mouse_movement();
}
