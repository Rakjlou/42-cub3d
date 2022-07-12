/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:55:44 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/12 01:23:47 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "bool.h"
# include "fterr.h"

# define E_USAGE_MSG "Usage: ./cub3d map.ber"
# define E_MALLOC_MSG "malloc failed"
# define E_MAP_OPEN_MSG "cannot open map file %s"
# define E_MAP_EMPTY_MSG "map file %s is empty, or maybe it's a directory idk"
# define E_MAP_EXT_MSG "%s: incorrect file extension"
# define E_MAP_EXT2_MSG "%s: weird file extension edge case error"
# define E_MAP_CHAR_MSG "map has at least one invalid character"
# define E_MAP_SPAWN_MISS_MSG "no spawn found on the map"
# define E_MAP_SPAWN_EXTRA_MSG "too much spawns on the map"
# define E_META_INVALID_MSG "%s is an invalid metadata identifier"
# define E_META_FORMAT_MSG "at least one metadata line has a wrong format"
# define E_COLOR_INVALID_MSG "at least one color component is too big (0 - 255)"
# define E_META_MISSING_MSG "at least a color or a texture is missing"

typedef enum e_error_code
{
	E_USAGE,
	E_MALLOC,
	E_MAP_OPEN,
	E_MAP_EMPTY,
	E_MAP_EXT,
	E_MAP_EXT2,
	E_MAP_CHAR,
	E_MAP_SPAWN_MISS,
	E_MAP_SPAWN_EXTRA,
	E_META_INVALID,
	E_META_FORMAT,
	E_COLOR_INVALID,
	E_META_MISSING
}	t_error_code;

t_bool	errors_register(void);

#endif
