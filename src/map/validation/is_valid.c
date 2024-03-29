/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:32:21 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/14 04:04:06 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/map_validation.h"

static t_bool	preliminary_tests(t_map_candidate *candidate)
{
	return (check_emptiness(candidate) && check_filename(candidate)
		&& check_map_chars(candidate) && check_spawn(candidate)
		&& check_metadata(candidate));
}

/*
	We first do the tests requiring no memory allocation.
	We then build a temporary map array in order to test properly the
	wall surroundings
*/
t_bool	map_candidate_is_valid(t_map_candidate *candidate)
{
	if (!preliminary_tests(candidate)
		|| !map_candidate_build_matrix(candidate)
		|| !check_walls(candidate))
		return (FALSE);
	return (TRUE);
}
