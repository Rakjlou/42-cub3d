/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:26:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/07 22:36:42 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATION_H
# define MAP_VALIDATION_H

# define MANDATORY_EXTENSION ".cub"
# define WALL_CHARS "1"
# define FLOOR_CHARS "0"
# define OUTSIDE_CHARS " "
# define SPAWN_CHARS "NSEW"
# define MAP_CHARS WALL_CHARS FLOOR_CHARS OUTSIDE_CHARS SPAWN_CHARS

# include "bool.h"
# include "map/map_candidate.h"
# include "errors.h"
# include "libft.h"
# include "ftprintf.h"

t_bool	check_emptiness(t_map_candidate *candidate);
t_bool	check_filename(t_map_candidate *candidate);
t_bool	check_map_chars(t_map_candidate *candidate);
t_bool	check_spawn(t_map_candidate *candidate);

#endif
