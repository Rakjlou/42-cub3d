/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:26:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/12 00:31:54 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATION_H
# define MAP_VALIDATION_H

# define MANDATORY_EXTENSION ".cub"
# define WALL_CHARS "1"
# define FLOOR_CHARS "0"
# define OUTSIDE_CHARS " "
# define SPAWN_CHARS "NSEW"
/*# define MAP_CHARS WALL_CHARS FLOOR_CHARS OUTSIDE_CHARS SPAWN_CHARS*/
# define MAP_CHARS " 10NSEW"

# define NORTH_ID "NO"
# define SOUTH_ID "SO"
# define EAST_ID "EA"
# define WEST_ID "WE"
# define FLOOR_ID "F"
# define CEILLING_ID "C"
# define META_ELEM_COUNT 6
# define META_ELEM_SIZE 2

# include "map/map_candidate.h"
# include "errors.h"
# include "libft.h"
# include "ftprintf.h"

t_bool	check_emptiness(t_map_candidate *candidate);
t_bool	check_filename(t_map_candidate *candidate);
t_bool	check_map_chars(t_map_candidate *candidate);
t_bool	check_spawn(t_map_candidate *candidate);
t_bool	check_metadata(t_map_candidate *candidate);

#endif
