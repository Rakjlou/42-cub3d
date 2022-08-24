/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/24 11:51:57 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/window.h"
#include "player.h"
#include "input.h"

#include "map/map_tile.h"
#include "map/map.h"

#include "ftprintf.h"

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
			player_rotate(player->rotation_speed);
		else
			player_rotate(-player->rotation_speed);
		++i;
	}
}

static t_bool	ignore_use(t_input *input)
{
	static int	ignore = 0;

	if (ignore > 0)
	{
		--ignore;
		return (TRUE);
	}
	else if (input->use)
	{
		ignore = 10;
		return (FALSE);
	}
	ignore = 0;
	return (FALSE);
}

static void	update_use(void)
{
	t_tile		*tile;
	t_input		*input;
	t_player	*player;
	t_ivector	target;

	input = _input();
	player = _player();
	if (ignore_use(input) || !input->use)
		return ;
	target.x = player->pos.x + (player->dir.x);
	target.y = player->pos.y + (player->dir.y);
	tile = map_get_tile(target.x, target.y);
	if (tile && tile->type == 'D')
		tile->type = 'A';
	else if (tile && tile->type == 'A')
		tile->type = 'D';
}

void	player_update(void)
{
	player_update_movement();
	update_mouse_movement();
	update_use();
}
