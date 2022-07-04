/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:07:37 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/01 21:22:40 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/map_validation.h"

t_bool	check_map_chars(t_map_candidate *candidate)
{
	t_iter	iter;
	char	*line;
	int		i;

	iter_init(&iter, &candidate->map, DESC);
	while (iter_next(&iter))
	{
		line = (char *)iter.data;
		i = 0;
		while (line[i])
		{
			if (!ft_cvalid(line[i], VALID_MAP_CHARS))
				return (fterr_set_error(E_MAP_CHAR), FALSE);
			++i;
		}
	}
	return (TRUE);
}
