/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/12 01:30:39 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "errors.h"
#include "render/window.h"
#include "mlx.h"

void	window_destroy(void)
{
	t_window	*window;

	window = _window();
	if (window->mlx == NULL)
		return ;
	if (window->buffer_image != NULL)
		mlx_destroy_image(window->mlx, window->buffer_image);
	if (window->core != NULL)
		mlx_destroy_window(window->mlx, window->core);
	mlx_destroy_display(window->mlx);
	free(window->mlx);
	ft_bzero(window, sizeof(t_window));
}
