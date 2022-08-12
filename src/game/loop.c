/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/12 14:44:47 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/render.h"
#include "render/window.h"
#include "mlx.h"

#include "map/map_tile.h"
#include "input.h"
#include "player.h"
#include "ftprintf.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static void	player_move_forward(void)
{
	int			dest_line;
	int			dest_column;
	t_player	*player;

	player = _player();
	dest_line = (int)(player->pos.x + player->dir.x * player->speed);
	dest_column = (int)player->pos.y;
	if (!tile_collides_by_pos(dest_line, dest_column))
		player->pos.x += player->dir.x * player->speed;
	dest_line = (int)player->pos.x;
	dest_column = (int)(player->pos.y + player->dir.y * player->speed);
	if (!tile_collides_by_pos(dest_line, dest_column))
		player->pos.y += player->dir.y * player->speed;
}

static void	player_move_backward(void)
{
	int			dest_line;
	int			dest_column;
	t_player	*player;

	player = _player();
	dest_line = (int)(player->pos.x - player->dir.x * player->speed);
	dest_column = (int)player->pos.y;
	if (!tile_collides_by_pos(dest_line, dest_column))
		player->pos.x -= player->dir.x * player->speed;
	dest_line = (int)(player->pos.x);
	dest_column = (int)(player->pos.y - player->dir.y * player->speed);
	if (!tile_collides_by_pos(dest_line, dest_column))
		player->pos.y -= player->dir.y * player->speed;
}

static void	player_move_left(void)
{
	int			dest_line;
	int			dest_column;
	t_dvector	left_dir;
	t_player	*player;

	player = _player();
	left_dir.x = -player->dir.y;
	left_dir.y = player->dir.x;
	dest_line = (int)(player->pos.x - left_dir.x * (player->speed / 2));
	dest_column = (int)player->pos.y;
	if (!tile_collides_by_pos(dest_line, dest_column))
		player->pos.x -= left_dir.x * (player->speed / 2);
	dest_line = (int)player->pos.x;
	dest_column = (int)(player->pos.y - left_dir.y * (player->speed / 2));
	if (!tile_collides_by_pos(dest_line, dest_column))
		player->pos.y -= left_dir.y * (player->speed / 2);
	if (player->pos.x == 1.0)
		exit(1);
}

static void	player_move_right(void)
{
	int			dest_line;
	int			dest_column;
	t_dvector	right_dir;
	t_player	*player;

	player = _player();
	right_dir.x = -player->dir.y;
	right_dir.y = player->dir.x;
	dest_line = (int)(player->pos.x + right_dir.x * (player->speed / 2));
	dest_column = (int)player->pos.y;
	if (!tile_collides_by_pos(dest_line, dest_column))
		player->pos.x += right_dir.x * (player->speed / 2);
	dest_line = (int)player->pos.x;
	dest_column = (int)(player->pos.y + right_dir.y * (player->speed / 2));
	if (!tile_collides_by_pos(dest_line, dest_column))
		player->pos.y += right_dir.y * (player->speed / 2);
}

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

static void	player_rotate_left(void)
{
	player_rotate(-_player()->rotation_speed);
}

static void	player_rotate_right(void)
{
	player_rotate(_player()->rotation_speed);
}

static void	game_update(void)
{
	t_input	*input;

	input = _input();
	input_debug();
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

int	game_loop_callback(void)
{
	game_update();
	render_walls();
	window_refresh();
	return (0);
}

void	game_loop(void)
{
	mlx_loop(_window()->mlx);
}
