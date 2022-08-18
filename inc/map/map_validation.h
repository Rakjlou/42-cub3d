/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:26:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/18 18:51:43 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATION_H
# define MAP_VALIDATION_H

# define MANDATORY_EXTENSION ".cub"
# define WALL_CHARS "1"
# define FLOOR_CHARS "0"
# define OUTSIDE_CHARS " "
# define SPAWN_NORTH "N"
# define SPAWN_SOUTH "S"
# define SPAWN_EAST "E"
# define SPAWN_WEST "W"
/*# define SPAWN_CHARS SPAWN_NORTH SPAWN_SOUTH SPAWN_EAST SPAWN_WEST*/
# define SPAWN_CHARS "NSEW"
/*# define MAP_CHARS WALL_CHARS FLOOR_CHARS OUTSIDE_CHARS SPAWN_CHARS*/
# define MAP_CHARS " 10NSEW"

# define FLOOR_VALIDATION 'F'

# define NORTH_ID "NO"
# define SOUTH_ID "SO"
# define EAST_ID "EA"
# define WEST_ID "WE"
# define FLOOR_ID "F"
# define CEILING_ID "C"
# define META_ELEM_SIZE 2
# define COLOR_COMPONENTS 3

# include "map/map_candidate.h"
# include "errors.h"
# include "libft.h"
# include "ftprintf.h"

typedef enum e_meta
{
	META_NORTH,
	META_SOUTH,
	META_EAST,
	META_WEST,
	META_FLOOR,
	META_CEILING,
	META_END
}	t_meta;

t_bool	check_emptiness(t_map_candidate *candidate);
t_bool	check_filename(t_map_candidate *candidate);
t_bool	check_map_chars(t_map_candidate *candidate);
t_bool	check_spawn(t_map_candidate *candidate);
t_bool	check_metadata(t_map_candidate *candidate);
t_bool	check_walls(t_map_candidate *candidate);
t_bool	tile_is_floor(int tile);
t_bool	tile_is_outside(int tile);

t_bool	check_metadata_missing(t_map_candidate *candidate);
t_bool	check_metadata_line_integrity(char **line_split);
t_bool	check_color_integrity(char **csp);
t_bool	check_color_component_integrity(char **csp, char *component);
t_bool	check_metadata_error(char **cmatrix, t_error_code error_code);
t_bool	check_metadata_error_printf(
			char **cmatrix,
			t_error_code error_code,
			char *data);

#endif
