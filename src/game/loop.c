/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/21 22:27:09 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/window.h"
#include "mlx.h"
#include "ftprintf.h"
#include "input.h"

int	game_loop_callback(void)
{
	ftfprintf(STDERR_FILENO, "Forward      %d\n", _input()->forward);
	ftfprintf(STDERR_FILENO, "Left         %d\n", _input()->left);
	ftfprintf(STDERR_FILENO, "Right        %d\n", _input()->right);
	ftfprintf(STDERR_FILENO, "Backward     %d\n", _input()->backward);
	ftfprintf(STDERR_FILENO, "Rotate Left  %d\n", _input()->rotate_left);
	ftfprintf(STDERR_FILENO, "Rotate Right %d\n", _input()->rotate_right);
	return (0);
}

void	game_loop(void)
{
	mlx_loop(_window()->mlx);
}
