/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_horizontal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/12 14:55:44 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "map/map_tile.h"

void	player_move_left(void)
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
}

void	player_move_right(void)
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
