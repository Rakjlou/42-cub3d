/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filename.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:40:52 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/01 21:16:34 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/map_validation.h"

t_bool	check_filename(t_map_candidate *candidate)
{
	char	*slash;
	size_t	ext_size;

	ext_size = ft_strlen(MANDATORY_EXTENSION);
	if (!ft_ends_with(candidate->filename, MANDATORY_EXTENSION))
		return (fterr_set(E_MAP_EXT, candidate->filename, NULL), FALSE);
	slash = ft_strrchr(candidate->filename, '/');
	if (slash == NULL)
		return (ft_strlen(candidate->filename) > ext_size);
	else if (ft_strlen(slash + 1) <= ext_size)
		return (fterr_set(E_MAP_EXT2, candidate->filename, NULL), FALSE);
	return (TRUE);
}
