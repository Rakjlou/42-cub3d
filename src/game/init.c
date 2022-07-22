/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/22 22:42:15 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ftprintf.h"
#include "errors.h"
#include "game.h"
#include "mlx.h"

static int	on_expose(void)
{
	ftfprintf(STDERR_FILENO, "expose_callback\n");
	return (0);
}

static int	on_close(void)
{
	ftfprintf(STDERR_FILENO, "close_callback\n");
	mlx_loop_end(_window()->mlx);
	return (0);
}

t_bool	game_init(char *mapfile)
{
	if (!map_init(mapfile) || !window_init())
		return (FALSE);
	player_init();
	input_init();
	window_set_expose_callback(on_expose);
	window_set_close_callback(on_close);
	window_set_loop_callback(game_loop_callback);
	return (TRUE);
}
