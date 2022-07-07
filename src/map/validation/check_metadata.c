/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_metadata.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:07:37 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/08 01:23:20 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/map_validation.h"

static t_bool	set_texture(char **texture, char *texture_raw)
{
	char	*raw_dup;

	raw_dup = ft_strdup(texture_raw);
	if (raw_dup == NULL)
		return (fterr_set_error(E_MALLOC), FALSE);
	*texture = raw_dup;
	return (TRUE);
}

static t_bool	set_color(int *color, char *color_raw)
{
	char	**color_split;
	int		tmp;

	color_split = ft_split(color_raw, ",");
	if (color_split == NULL)
		return (fterr_set_error(E_MALLOC), FALSE);
	else if (ft_cmatrix_size(color_split) != 3)
		return (fterr_set_error(E_META_FORMAT_MSG), FALSE);
	/* WIP */
	return (TRUE);
}

static t_bool	check_specific_meta(
	t_map_candidate *candidate,
	char **meta,
	int meta_identifier)
{
	if (meta_identifier == 0)
		return (set_texture(&candidate->north_texture, meta[1]));
	else if (meta_identifier == 1)
		return (set_texture(&candidate->south_texture, meta[1]));
	else if (meta_identifier == 2)
		return (set_texture(&candidate->east_texture, meta[1]));
	else if (meta_identifier == 3)
		return (set_texture(&candidate->west_texture, meta[1]));
	else if (meta_identifier == 4)
		return (set_color(&candidate->floor_color, meta[1]));
	else if (meta_identifier == 5)
		return (set_color(&candidate->ceilling_color, meta[1]));
	return (FALSE);
}

static t_bool	check_meta_line(t_map_candidate *candidate, char **meta)
{
	static char	*element_candidate[META_ELEM_COUNT] = {
		NORTH_ID,
		SOUTH_ID,
		EAST_ID,
		WEST_ID,
		FLOOR_ID,
		CEILLING_ID
	};
	int			i;

	i = 0;
	while (i < META_ELEM_COUNT)
	{
		if (!ft_strncmp(element_candidate[i], meta[0], -1))
			return (check_specific_meta(candidate, meta, i));
		++i;
	}
	return (fterr_set(E_INVALID_META, ft_strdup(element[0]), free), FALSE);
}

t_bool	check_metadata(t_map_candidate *candidate)
{
	t_iter	iter;
	char	*line;
	char	**line_split;

	iter_init(&iter, &candidate->meta, DESC);
	while (iter_next(&iter))
	{
		line = (char *)iter.data;
		line_split = ft_split(line, " \t\v\n\f\r");
		if (line_split == NULL)
			return (fterr_set_error(E_MALLOC), FALSE);
		else if (ft_cmatrix_size(line_split) != META_ELEM_SIZE)
			return (ft_cmatrix_free(line_split),
				fterr_set_error(E_META_FORMAT), FALSE);
	}
	return (TRUE);
}
