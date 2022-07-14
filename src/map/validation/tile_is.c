/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_is.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 03:12:04 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/14 03:31:31 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/map_validation.h"

t_bool	tile_is_floor(int tile)
{
	return (ft_strchr(FLOOR_CHARS, tile) || ft_strchr(SPAWN_CHARS, tile));
}

t_bool	tile_is_outside(int tile)
{
	return (ft_strchr(OUTSIDE_CHARS, tile) != NULL);
}
