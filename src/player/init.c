/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/22 21:55:02 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/map.h"
#include "map/map_validation.h"
#include "player.h"

static void	set_player_spawn_vectors(t_tile *tile)
{
	if (ft_strchr(SPAWN_CHARS, tile->type) != NULL)
	{
		_player()->position.x = tile->x + 0.5;
		_player()->position.y = tile->y + 0.5;
	}
}

void	player_init(void)
{
	map_iterate(set_player_spawn_vectors);
}
