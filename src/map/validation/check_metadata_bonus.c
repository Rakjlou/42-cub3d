/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_metadata_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:07:37 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/24 12:26:20 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "map/map_validation.h"

static t_bool	set_texture(char **texture, char *texture_raw)
{
	char	*raw_dup;

	raw_dup = ft_strdup(texture_raw);
	if (raw_dup == NULL)
		return (check_metadata_error(NULL, E_MALLOC));
	if (texture && *texture != NULL)
		free(*texture);
	*texture = raw_dup;
	return (TRUE);
}

static t_bool	check_set_color(t_color *color, char *color_raw)
{
	char	**color_split;
	char	*component;
	int		i;

	i = 0;
	color_split = ft_split(color_raw, ",");
	if (!check_color_integrity(color_split))
		return (FALSE);
	while (i < COLOR_COMPONENTS)
	{
		component = color_split[i];
		if (!check_color_component_integrity(color_split, component))
			return (FALSE);
		++i;
	}
	*color = color_build_str(color_split[0], color_split[1],
			color_split[2], "0");
	return (ft_cmatrix_free(color_split), TRUE);
}

static t_bool	check_specific_meta(
	t_map_candidate *candidate,
	char *meta_value,
	int meta)
{
	if (meta == META_NORTH)
		return (set_texture(&candidate->north_texture, meta_value));
	else if (meta == META_SOUTH)
		return (set_texture(&candidate->south_texture, meta_value));
	else if (meta == META_EAST)
		return (set_texture(&candidate->east_texture, meta_value));
	else if (meta == META_WEST)
		return (set_texture(&candidate->west_texture, meta_value));
	else if (meta == META_FLOOR)
	{
		candidate->floor_color_set = TRUE;
		return (check_set_color(&candidate->floor_color, meta_value));
	}
	else if (meta == META_CEILING)
	{
		candidate->ceiling_color_set = TRUE;
		return (check_set_color(&candidate->ceiling_color, meta_value));
	}
	return (FALSE);
}

static t_bool	check_meta_line(t_map_candidate *candidate, char **meta)
{
	int		i;
	char	*meta_id;
	char	*meta_value;
	char	*meta_candidate[META_END];

	if (!check_metadata_line_integrity(meta))
		return (FALSE);
	i = 0;
	meta_id = meta[0];
	meta_value = meta[1];
	meta_candidate[META_NORTH] = NORTH_ID;
	meta_candidate[META_SOUTH] = SOUTH_ID;
	meta_candidate[META_EAST] = EAST_ID;
	meta_candidate[META_WEST] = WEST_ID;
	meta_candidate[META_FLOOR] = FLOOR_ID;
	meta_candidate[META_CEILING] = CEILING_ID;
	while (i < META_END)
	{
		if (!ft_strncmp(meta_candidate[i], meta_id, -1))
			return (check_specific_meta(candidate, meta_value, i));
		++i;
	}
	return (check_metadata_error_printf(NULL, E_META_INVALID, meta_id));
}

t_bool	check_metadata(t_map_candidate *candidate)
{
	t_iter	iter;
	char	**line_split;

	iter_init(&iter, &candidate->meta, DESC);
	while (iter_next(&iter))
	{
		line_split = ft_split((char *)iter.data, " \t\v\n\f\r");
		if (!check_meta_line(candidate, line_split))
			return (ft_cmatrix_free(line_split), FALSE);
		ft_cmatrix_free(line_split);
	}
	return (check_metadata_missing(candidate));
}
