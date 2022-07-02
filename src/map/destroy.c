/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/01 18:27:22 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map/map_candidate.h"

void	map_candidate_destroy(t_map_candidate *candidate)
{
	lst_destroy_nodes(&candidate->lines, free);
	lst_destroy_nodes(&candidate->map, free);
	lst_destroy_nodes(&candidate->meta, free);
}
