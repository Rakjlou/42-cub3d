/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/11 23:58:08 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/window.h"
#include "render/render.h"
#include "mlx.h"
#include "ftprintf.h"
#include "input.h"

int	game_loop_callback(void)
{
	ftfprintf(STDERR_FILENO, "BEG\n");
	render_background();
	window_refresh();
	ftfprintf(STDERR_FILENO, "END\n");
	return (0);
}

void	game_loop(void)
{
	mlx_loop(_window()->mlx);
}
