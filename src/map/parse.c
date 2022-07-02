/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:29:57 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/01 20:35:23 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bool.h"
#include "fterr.h"
#include "errors.h"
#include "map/map_candidate.h"

static t_bool	load_line_in_list(char *line, t_lst *lst)
{
	char	*line_dup;

	line_dup = ft_strdup(line);
	if (line_dup == NULL || !lst_push_back(lst, line_dup))
		return (fterr_set_error(E_MALLOC), FALSE);
	return (TRUE);
}

static t_bool	parse_meta_line(t_map_candidate *candidate, char *line_trimmed)
{
	if (ft_strlen(line_trimmed) == 0)
		return (TRUE);
	return (load_line_in_list(line_trimmed, &candidate->meta));
}

/*
	This function first checks if line_trimmed is empty, and changes the
	parse_mode to M_META if it is the case.
	If it is not the case, it then trims the line of it's ending newline
	character, and hydrates the map candidate.
*/
static t_bool	parse_map_line(
	t_map_candidate *candidate,
	char *line,
	char *line_trimmed,
	t_parse_mode *parse_mode)
{
	char	*line_dup;
	size_t	line_trimmed_size;

	line_trimmed_size = ft_strlen(line_trimmed);
	if (line_trimmed_size == 0)
		*parse_mode = M_META;
	else
	{
		line_dup = ft_strtrim(line, "\n");
		if (line_dup == NULL || !lst_push_front(&candidate->map, line_dup))
			return (fterr_set_error(E_MALLOC), FALSE);
	}
	return (TRUE);
}

/*
	We read the file from the bottom to the top. This state is stored
	in parse_mode.
	parse_map_line() will change parse_mode to M_META as soon as the trimmed line
	is empty. This doesn't allow empty lines after map definition, but it is
	tweakable to achieve this if necessary.
*/
t_bool	map_candidate_parse(t_map_candidate *candidate)
{
	t_iter			iter;
	t_parse_mode	parse_mode;
	char			*line;
	char			*line_trimmed;

	parse_mode = M_MAP;
	iter_init(&iter, &candidate->lines, DESC);
	while (iter_next(&iter))
	{
		line = (char *)iter.data;
		line_trimmed = ft_strtrim(line, MAP_TRIM);
		if (parse_mode == M_MAP)
		{
			if (!parse_map_line(candidate, line, line_trimmed, &parse_mode))
				return (free(line_trimmed), FALSE);
		}
		else if (!parse_meta_line(candidate, line_trimmed))
			return (free(line_trimmed), FALSE);
		free(line_trimmed);
	}
	return (TRUE);
}
