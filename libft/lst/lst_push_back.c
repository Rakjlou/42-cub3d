/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 03:53:47 by nsierra-          #+#    #+#             */
/*   Updated: 2021/12/02 04:11:09 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlst.h"

int	lst_push_back(t_lst *lst, void *data)
{
	t_node				*node;

	node = node_new(data);
	if (node == NULL)
		return (0);
	else if (lst->size == 0)
	{
		node->prev = node;
		node->next = node;
		lst->first = node;
	}
	else
		node_insert_between(node, lst_node_back(lst), lst_node_front(lst));
	return (++lst->size);
}
