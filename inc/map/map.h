/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:26:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/20 22:18:47 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "libft.h"
# include "render/color.h"

typedef struct s_texture
{
	char	*filename;
}	t_texture;

typedef struct s_tile
{
	unsigned char	type;
	int				x;
	int				y;
}	t_tile;

typedef struct s_map
{
	int			height;
	int			width;
	char		*filename;
	t_texture	texture_north;
	t_texture	texture_south;
	t_texture	texture_east;
	t_texture	texture_west;
	t_color		color_floor;
	t_color		color_ceiling;
	t_tile		**data;
}	t_map;

t_map	*_map(void);

t_bool	map_init(char *filename);
void	map_debug(void);
void	map_destroy(void);

#endif
