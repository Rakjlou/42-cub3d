/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:55:44 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/01 21:20:29 by nsierra-         ###   ########.fr       */
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

typedef enum e_error_code
{
	E_USAGE,
	E_MALLOC,
	E_MAP_OPEN,
	E_MAP_EMPTY,
	E_MAP_EXT,
	E_MAP_EXT2,
	E_MAP_CHAR
}	t_error_code;

t_bool	errors_register(void);

#endif
