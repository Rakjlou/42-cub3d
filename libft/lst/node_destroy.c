/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 04:17:42 by nsierra-          #+#    #+#             */
/*   Updated: 2021/12/02 06:16:10 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlst.h"
#include <stdlib.h>

void	*node_destroy(t_node **node, void (*del)(void *))
{
	t_node		*node_destroyed;
	t_node		*left;
	t_node		*right;
	void		*data;

	node_destroyed = *node;
	if (!(node_destroyed->next == node_destroyed))
	{
		left = node_destroyed->prev;
		right = node_destroyed->next;
		left->next = right;
		right->prev = left;
	}
	data = node_destroyed->data;
	free(node_destroyed);
	*node = NULL;
	if (del == NULL)
		return (data);
	del(data);
	return (NULL);
}
