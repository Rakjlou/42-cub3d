/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tile.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:26:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/11 22:56:38 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TILE_H
# define MAP_TILE_H

# include "libft.h"

typedef struct s_tile
{
	unsigned char	type;
	int				x;
	int				y;
}	t_tile;

t_bool	tile_is(t_tile *tile, unsigned char type);
t_bool	tile_is_wall(t_tile *tile);
t_bool	tile_collides_by_pos(int line, int column);

#endif
