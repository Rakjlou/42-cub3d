/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_metadata.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:07:37 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/14 01:54:11 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "map/map_validation.h"

static t_bool	set_texture(char **texture, char *texture_raw)
{
	char	*raw_dup;

	raw_dup = ft_strdup(texture_raw);
	if (raw_dup == NULL)
		return (fterr_set_error(E_MALLOC), FALSE);
	if (texture && *texture != NULL)
		free(*texture);
	*texture = raw_dup;
	return (TRUE);
}

/* "csp" is just a shorthand for "color_split" for norm reasons */
static t_bool	check_set_color(t_color *color, char *color_raw)
{
	char	**csp;

	csp = ft_split(color_raw, ",");
	if (csp == NULL)
		return (fterr_set_error(E_MALLOC), FALSE);
	else if (ft_cmatrix_size(csp) != 3 || !ft_str_all(csp[0], ft_isdigit)
		|| !ft_str_all(csp[1], ft_isdigit) || !ft_str_all(csp[0], ft_isdigit))
	{
		return (ft_cmatrix_free(csp), fterr_set_error(E_META_FORMAT), FALSE);
	}
	else if (ft_strlen(csp[0]) > 3 || ft_strlen(csp[1]) > 3
		|| ft_strlen(csp[2]) > 3 || ft_atoi(csp[0]) > UCHAR_MAX
		|| ft_atoi(csp[1]) > UCHAR_MAX || ft_atoi(csp[2]) > UCHAR_MAX)
	{
		return (ft_cmatrix_free(csp), fterr_set_error(E_COLOR_INVALID), FALSE);
	}
	*color = color_build((unsigned char)ft_atoi(csp[0]),
			(unsigned char)ft_atoi(csp[1]),
			(unsigned char)ft_atoi(csp[2]),
			UCHAR_MAX);
	return (ft_cmatrix_free(csp), TRUE);
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
	{
		candidate->floor_color_set = TRUE;
		return (check_set_color(&candidate->floor_color, meta[1]));
	}
	else if (meta_identifier == 5)
	{
		candidate->ceilling_color_set = TRUE;
		return (check_set_color(&candidate->ceilling_color, meta[1]));
	}
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
	return (fterr_set(E_META_INVALID, ft_strdup(meta[0]), free), FALSE);
}

t_bool	check_metadata(t_map_candidate *candidate)
{
	t_iter	iter;
	char	**line_split;

	iter_init(&iter, &candidate->meta, DESC);
	while (iter_next(&iter))
	{
		line_split = ft_split((char *)iter.data, " \t\v\n\f\r");
		if (line_split == NULL)
			return (fterr_set_error(E_MALLOC), FALSE);
		else if (ft_cmatrix_size(line_split) != META_ELEM_SIZE)
		{
			return (ft_cmatrix_free(line_split),
				fterr_set_error(E_META_FORMAT), FALSE);
		}
		else if (!check_meta_line(candidate, line_split))
			return (ft_cmatrix_free(line_split), FALSE);
		ft_cmatrix_free(line_split);
	}
	if (!candidate->north_texture || !candidate->south_texture
		|| !candidate->east_texture || !candidate->west_texture
		|| !candidate->floor_color_set || !candidate->ceilling_color_set)
	{
		return (fterr_set_error(E_META_MISSING), FALSE);
	}
	return (TRUE);
}
