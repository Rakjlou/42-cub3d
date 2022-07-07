/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spawn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:07:37 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/07 22:40:49 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/map_validation.h"

/* TODO: check if the spawn is inside the map */
t_bool	check_spawn(t_map_candidate *candidate)
{
	t_iter	iter;
	char	*line;
	int		i;
	int		count;

	count = 0;
	iter_init(&iter, &candidate->map, DESC);
	while (iter_next(&iter))
	{
		line = (char *)iter.data;
		i = 0;
		while (line[i])
		{
			if (ft_strchr(SPAWN_CHARS, line[i]) != NULL)
				++count;
			++i;
		}
	}
	if (count > 1)
		return (fterr_set_error(E_MAP_SPAWN_EXTRA), FALSE);
	else if (count == 0)
		return (fterr_set_error(E_MAP_SPAWN_MISS), FALSE);
	return (TRUE);
}
