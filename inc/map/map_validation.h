/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:26:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/01 21:20:59 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATION_H
# define MAP_VALIDATION_H

# define MANDATORY_EXTENSION ".cub"
# define VALID_MAP_CHARS " 01NSEW"

# include "bool.h"
# include "map/map_candidate.h"
# include "errors.h"
# include "libft.h"
# include "ftprintf.h"

t_bool	check_emptiness(t_map_candidate *candidate);
t_bool	check_filename(t_map_candidate *candidate);
t_bool	check_map_chars(t_map_candidate *candidate);

#endif
