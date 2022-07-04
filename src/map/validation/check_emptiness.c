/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_emptiness.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:40:52 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/01 20:55:18 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/map_candidate.h"
#include "errors.h"
#include "bool.h"

t_bool	check_emptiness(t_map_candidate *candidate)
{
	if (candidate->lines.size == 0)
		return (fterr_set(E_MAP_EMPTY, candidate->filename, NULL), FALSE);
	return (TRUE);
}
