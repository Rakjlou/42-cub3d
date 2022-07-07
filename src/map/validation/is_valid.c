/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:32:21 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/07 22:42:38 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/map_validation.h"

t_bool	map_candidate_is_valid(t_map_candidate *candidate)
{
	if (!check_emptiness(candidate) || !check_filename(candidate)
		|| !check_map_chars(candidate) || !check_spawn(candidate))
		return (FALSE);
	return (TRUE);
}
