/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:32:21 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/01 20:33:26 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_bool	map_candidate_is_valid(t_map_candidate *candidate)
{
	if (candidate->lines.size == 0)
		return (fterr_set(E_MAP_EMPTY, candidate->filename, NULL), FALSE);
	return (TRUE);
}
