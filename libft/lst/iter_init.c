/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 05:09:51 by nsierra-          #+#    #+#             */
/*   Updated: 2021/12/02 07:49:48 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlst.h"
#include <limits.h>

void	iter_init(t_iter *it, t_lst *lst, t_lst_direction dir)
{
	ft_bzero(it, sizeof(t_iter));
	it->dir = dir;
	it->lst = lst;
}

/*
void	iter_init(t_iter *it, t_lst *lst, t_lst_direction dir)
{
	if (dir == asc)
	{
		it->pos = INT_MAX;
		it->current = lst_node_front(lst);
		it->end = lst_node_back(lst);
	}
	else
	{
		it->pos = lst->size;
		it->current = lst_node_back(lst);
		it->end = lst_node_front(lst);
	}
	it->dir = dir;
	it->flag = 0;
	it->lst = lst;
}
*/
