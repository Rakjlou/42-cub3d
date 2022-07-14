/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/13 23:30:18 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map/map_candidate.h"

void	map_candidate_destroy(t_map_candidate *candidate)
{
	lst_destroy_nodes(&candidate->lines, free);
	lst_destroy_nodes(&candidate->map, free);
	lst_destroy_nodes(&candidate->meta, free);
	free(candidate->north_texture);
	free(candidate->south_texture);
	free(candidate->east_texture);
	free(candidate->west_texture);
	if (candidate->matrix != NULL)
		ft_cmatrix_free(candidate->matrix);
}
