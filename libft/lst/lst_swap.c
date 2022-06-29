/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 04:28:14 by nsierra-          #+#    #+#             */
/*   Updated: 2021/12/02 04:28:59 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlst.h"

void	lst_swap(t_lst *lst, size_t pos1, size_t pos2)
{
	t_node	*cursor1;
	t_node	*cursor2;

	if (pos1 >= lst->size || pos2 >= lst->size || pos1 == pos2)
		return ;
	cursor1 = lst_node_at(lst, pos1);
	cursor2 = lst_node_at(lst, pos2);
	node_swap(cursor1, cursor2);
}
