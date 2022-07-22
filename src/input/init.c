/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/22 22:42:22 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"
#include "ftprintf.h"

static int	on_keydown(int key)
{
	t_input	*input;

	input = _input();
	if (key == KEY_ESCAPE)
		mlx_loop_end(_window()->mlx);
	else if (key == KEY_FORWARD)
		input->forward = TRUE;
	else if (key == KEY_LEFT)
		input->left = TRUE;
	else if (key == KEY_RIGHT)
		input->right = TRUE;
	else if (key == KEY_BACKWARD)
		input->backward = TRUE;
	else if (key == KEY_ARROW_LEFT)
		input->rotate_left = TRUE;
	else if (key == KEY_ARROW_RIGHT)
		input->rotate_right = TRUE;
	return (0);
}

static int	on_keyup(int key)
{
	t_input	*input;

	input = _input();
	if (key == KEY_ESCAPE)
		mlx_loop_end(_window()->mlx);
	else if (key == KEY_FORWARD)
		input->forward = FALSE;
	else if (key == KEY_LEFT)
		input->left = FALSE;
	else if (key == KEY_RIGHT)
		input->right = FALSE;
	else if (key == KEY_BACKWARD)
		input->backward = FALSE;
	else if (key == KEY_ARROW_LEFT)
		input->rotate_left = FALSE;
	else if (key == KEY_ARROW_RIGHT)
		input->rotate_right = FALSE;
	return (0);
}

static int	on_click(int a, int b, int c)
{
	ftfprintf(STDERR_FILENO, "mouse_callback a %d b %d c %d\n", a, b, c);
	return (0);
}

void	input_init(void)
{
	window_set_keydown_callback(on_keydown);
	window_set_keyup_callback(on_keyup);
	window_set_mouse_click_callback(on_click);
}
