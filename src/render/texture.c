/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/21 19:59:01 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "errors.h"
#include "render/window.h"
#include "map/map.h"
#include "mlx.h"

t_bool	texture_hydrate(t_texture *texture)
{
	t_window	*window;

	window = _window();
	texture->image = mlx_xpm_file_to_image(
			window->mlx,
			texture->filename,
			&texture->width,
			&texture->height);
	if (texture->image == NULL)
		return (fterr_set_error(E_MLX_XPM_FAILURE), FALSE);
	texture->buffer = mlx_get_data_addr(
			texture->image,
			&texture->depth,
			&texture->line_size,
			&texture->endian);
	return (TRUE);
}

void	texture_destroy(t_texture *texture)
{
	free(texture->filename);
	if (texture->image != NULL)
		mlx_destroy_image(_window()->mlx, texture->image);
	ft_bzero(texture, sizeof(t_texture));
}
