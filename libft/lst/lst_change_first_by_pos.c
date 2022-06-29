/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_change_first_by_pos.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 04:22:39 by nsierra-          #+#    #+#             */
/*   Updated: 2021/12/02 04:25:53 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlst.h"

void	lst_change_first_by_pos(t_lst *lst, size_t pos)
{
	t_node		*node;

	node = lst_node_at(lst, pos);
	if (node == NULL)
		return ;
	lst_change_first_by_node(lst, node);
}
