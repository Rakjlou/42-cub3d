/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 05:17:31 by nsierra-          #+#    #+#             */
/*   Updated: 2021/12/02 07:57:27 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlst.h"
#include <stdio.h>

static void	init_asc(t_iter *it)
{
	it->pos = 0;
	it->current = lst_node_front(it->lst);
	it->end = lst_node_back(it->lst);
}

static void	init_desc(t_iter *it)
{
	it->pos = it->lst->size - 1;
	it->current = lst_node_back(it->lst);
	it->end = lst_node_front(it->lst);
}

int	iter_next(t_iter *it)
{
	if (it->lst->size == 0 || (it->current == it->end && it->current != NULL))
		return (0);
	else if (it->current == NULL && it->dir == ASC)
		init_asc(it);
	else if (it->current == NULL && it->dir == DESC)
		init_desc(it);
	else if (it->dir == ASC)
	{
		it->pos++;
		it->current = it->current->next;
	}
	else if (it->dir == DESC)
	{
		it->pos--;
		it->current = it->current->prev;
	}
	it->data = it->current->data;
	return (1);
}
