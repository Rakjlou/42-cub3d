/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_candidate.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:26:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/12 01:19:03 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CANDIDATE_H
# define MAP_CANDIDATE_H

# define MAP_TRIM " \t\n\r\v\f"

# include "ftlst.h"
# include "mlx/color.h"

typedef enum e_parse_mode
{
	M_MAP,
	M_META
}	t_parse_mode;

typedef struct s_map_candidate
{
	char	*filename;
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	t_color	floor_color;
	t_color	ceilling_color;
	t_bool	floor_color_set;
	t_bool	ceilling_color_set;
	t_lst	lines;
	t_lst	map;
	t_lst	meta;
}	t_map_candidate;

t_bool	map_candidate_parse(t_map_candidate *candidate);
void	map_candidate_destroy(t_map_candidate *candidate);
t_bool	map_candidate_is_valid(t_map_candidate *candidate);

#endif
