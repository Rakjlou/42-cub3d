/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 04:21:10 by nsierra-          #+#    #+#             */
/*   Updated: 2021/12/02 05:28:57 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlst.h"

int	lst_insert(t_lst *lst, void *data, size_t pos)
{
	t_node				*cursor;

	if (lst->size == 0 || pos == 0)
		return (lst_push_front(lst, data));
	if (pos >= lst->size)
		return (0);
	cursor = lst_node_at(lst, pos);
	node_insert_between(node_new(data), cursor->prev, cursor);
	return (++lst->size);
}
