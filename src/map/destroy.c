/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/21 19:55:02 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map/map_candidate.h"
#include "map/map.h"

static void	destroy_map_data(t_map *map)
{
	int	line;

	line = 0;
	while (line < map->height)
		free(map->data[line++]);
	free(map->data);
	map->data = NULL;
}

void	map_candidate_destroy(t_map_candidate *candidate)
{
	lst_destroy_nodes(&candidate->lines, free);
	lst_destroy_nodes(&candidate->map, free);
	lst_destroy_nodes(&candidate->meta, free);
	free(candidate->north_texture);
	free(candidate->south_texture);
	free(candidate->east_texture);
	free(candidate->west_texture);
	if (candidate->matrix != NULL)
		ft_cmatrix_free(candidate->matrix);
}

void	map_destroy(void)
{
	t_map	*map;

	map = _map();
	texture_destroy(&map->texture_north);
	texture_destroy(&map->texture_south);
	texture_destroy(&map->texture_east);
	texture_destroy(&map->texture_west);
	destroy_map_data(map);
}
