/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_vertical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/12 14:56:21 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "map/map_tile.h"

void	player_move_forward(void)
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

void	player_move_backward(void)
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
