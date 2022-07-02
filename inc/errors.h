/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:55:44 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/01 16:39:27 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "bool.h"

# define E_USAGE_MSG "Usage: ./cub3d map.ber"
# define E_MALLOC_MSG "malloc failed"
# define E_MAP_OPEN_MSG "cannot open map file %s"
# define E_MAP_EMPTY_MSG "map file %s is empty, or maybe it's a directory idk"

typedef enum e_error_code
{
	E_USAGE,
	E_MALLOC,
	E_MAP_OPEN,
	E_MAP_EMPTY
}	t_error_code;

t_bool	errors_register(void);

#endif
