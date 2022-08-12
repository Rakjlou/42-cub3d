/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_is.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/11 22:58:23 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map/map.h"
#include "map/map_validation.h"

t_bool	tile_is(t_tile *tile, unsigned char type)
{
	return (tile->type == type);
}

t_bool	tile_is_wall(t_tile *tile)
{
	return (ft_strchr(WALL_CHARS, tile->type) != NULL);
}
