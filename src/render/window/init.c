/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/21 00:17:45 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "render/window.h"
#include "mlx.h"

t_bool	window_init(void)
{
	t_window	*window;

	window = _window();
	window->mlx = mlx_init();
	if (window->mlx == NULL)
		return (fterr_set_error(E_MLX_FAILURE), FALSE);
	window->core = mlx_new_window(
			window->mlx,
			WINDOW_HEIGHT, WINDOW_WIDTH, WINDOW_TITLE);
	if (window->core == NULL)
		return (fterr_set_error(E_MLX_FAILURE), FALSE);
	return (TRUE);
}
