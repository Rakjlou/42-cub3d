/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/21 21:11:07 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ftprintf.h"
#include "errors.h"
#include "game.h"
#include "mlx.h"

static int	key_callback(int key)
{
	if (key == KEY_ESCAPE)
		mlx_loop_end(_window()->mlx);
	else if (key == KEY_FORWARD)
		ftfprintf(STDOUT_FILENO, "KEY_FORWARD\n");
	else if (key == KEY_LEFT)
		ftfprintf(STDOUT_FILENO, "KEY_LEFT\n");
	else if (key == KEY_RIGHT)
		ftfprintf(STDOUT_FILENO, "KEY_RIGHT\n");
	else if (key == KEY_BACKWARD)
		ftfprintf(STDOUT_FILENO, "KEY_BACKWARD\n");
	else if (key == KEY_ARROW_LEFT)
		ftfprintf(STDOUT_FILENO, "KEY_ARROW_LEFT\n");
	else if (key == KEY_ARROW_RIGHT)
		ftfprintf(STDOUT_FILENO, "KEY_ARROW_RIGHT\n");
	return (0);
}

static int	mouse_callback(int a, int b, int c)
{
	ftfprintf(STDOUT_FILENO, "mouse_callback a %d b %d c %d\n", a, b, c);
	return (0);
}

static int	expose_callback(void)
{
	ftfprintf(STDOUT_FILENO, "expose_callback\n");
	return (0);
}

static int	close_callback(void)
{
	ftfprintf(STDOUT_FILENO, "close_callback\n");
	mlx_loop_end(_window()->mlx);
	return (0);
}

static int	loop_callback(void)
{
	return (0);
}

t_bool	game_init(char *mapfile)
{
	if (!map_init(mapfile) || !window_init())
		return (FALSE);
	window_set_key_callback(key_callback);
	window_set_mouse_callback(mouse_callback);
	window_set_expose_callback(expose_callback);
	window_set_close_callback(close_callback);
	window_set_loop_callback(loop_callback);
	return (TRUE);
}
