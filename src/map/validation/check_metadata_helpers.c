/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_metadata_helpers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:07:37 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/18 22:41:14 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "map/map_validation.h"

t_bool	check_metadata_missing(t_map_candidate *candidate)
{
	if (!candidate->north_texture)
		return (check_metadata_error_printf(NULL, E_META_MISSING, NORTH_ID));
	else if (!candidate->south_texture)
		return (check_metadata_error_printf(NULL, E_META_MISSING, SOUTH_ID));
	else if (!candidate->east_texture)
		return (check_metadata_error_printf(NULL, E_META_MISSING, EAST_ID));
	else if (!candidate->west_texture)
		return (check_metadata_error_printf(NULL, E_META_MISSING, WEST_ID));
	else if (!candidate->floor_color_set)
		return (check_metadata_error_printf(NULL, E_META_MISSING, FLOOR_ID));
	else if (!candidate->ceilling_color_set)
		return (check_metadata_error_printf(NULL, E_META_MISSING, CEILING_ID));
	return (TRUE);
}

t_bool	check_metadata_line_integrity(char **line_split)
{
	if (line_split == NULL)
		return (fterr_set_error(E_MALLOC), FALSE);
	else if (ft_cmatrix_size(line_split) != META_ELEM_SIZE)
		return (check_metadata_error(NULL, E_META_FORMAT));
	return (TRUE);
}

t_bool	check_color_integrity(char **csp)
{
	if (csp == NULL)
		return (check_metadata_error(NULL, E_MALLOC));
	else if (ft_cmatrix_size(csp) != COLOR_COMPONENTS)
		return (check_metadata_error(csp, E_META_FORMAT));
	return (TRUE);
}

t_bool	check_color_component_integrity(char **csp, char *component)
{
	int		component_value;

	component_value = ft_atoi(component);
	if (!ft_str_all(component, ft_isdigit) || ft_strlen(component) > 3)
		return (check_metadata_error_printf(csp, E_COLOR_DEF, component));
	else if (component_value < 0 || component_value > UCHAR_MAX)
		return (check_metadata_error_printf(csp, E_COLOR_VAL, component));
	return (TRUE);
}
