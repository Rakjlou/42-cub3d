/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 22:30:23 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/14 03:06:31 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/map_validation.h"

static void	hydrate_size(t_map_candidate *candidate)
{
	t_iter	iter;
	char	*line;
	size_t	longest;
	size_t	tmp;

	longest = 0;
	iter_init(&iter, &candidate->map, ASC);
	while (iter_next(&iter))
	{
		line = (char *)iter.data;
		tmp = ft_strlen(line);
		if (tmp > longest)
			longest = tmp;
	}
	candidate->height = (int)candidate->map.size;
	candidate->width = (int)longest;
}

static t_bool	hydrate_raw_matrix(t_map_candidate *candidate)
{
	size_t	i;
	size_t	height;
	size_t	width;
	char	*raw_line;

	i = 0;
	height = (size_t)candidate->height;
	width = (size_t)candidate->width;
	candidate->matrix = ft_calloc(height + 1, sizeof(char **));
	if (candidate->matrix == NULL)
		return (fterr_set_error(E_MALLOC), FALSE);
	while (i < height)
	{
		raw_line = (char *)lst_data_at(&candidate->map, i);
		candidate->matrix[i] = ft_calloc(width, sizeof(char *));
		if (candidate->matrix[i] == NULL)
			return (fterr_set_error(E_MALLOC), FALSE);
		ft_fill_str(candidate->matrix[i], OUTSIDE_CHARS[0], width);
		ft_memcpy(candidate->matrix[i], raw_line, ft_strlen(raw_line));
		++i;
	}
	return (TRUE);
}

t_bool	map_candidate_build_matrix(t_map_candidate *candidate)
{
	t_bool	result;

	hydrate_size(candidate);
	result = hydrate_raw_matrix(candidate);
	return (result);
}
