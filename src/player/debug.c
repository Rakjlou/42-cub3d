/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/24 11:21:51 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "ftprintf.h"
#include <stdio.h>

/*
void	player_debug(void)
{
	t_player	*p;

	p = _player();
	ftfprintf(STDERR_FILENO, "vvv PLAYER DEBUG vvv\n");
	dprintf(STDERR_FILENO, "Position:  %f (%d) %f (%d)\n",
		p->pos.x, (int)p->pos.x, p->pos.y, (int)p->pos.y);
	dprintf(STDERR_FILENO, "Direction: %f %f\n", p->dir.x, p->dir.y);
	dprintf(STDERR_FILENO, "FOV:       %f %f\n", p->fov.x, p->fov.y);
	dprintf(STDERR_FILENO, "Speed:     %f\n", p->speed);
	dprintf(STDERR_FILENO, "RSpeed:    %f\n", p->rotation_speed);
	ftfprintf(STDERR_FILENO, "^^^ PLAYER DEBUG ^^^\n");
}
*/

void	player_debug(void)
{
	t_player	*p;

	p = _player();
	ftfprintf(STDERR_FILENO, "vvv PLAYER DEBUG vvv\n");
	ftfprintf(STDERR_FILENO, "^^^ PLAYER DEBUG ^^^\n");
}
