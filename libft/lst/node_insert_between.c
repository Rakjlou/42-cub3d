/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_insert_between.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 04:08:31 by nsierra-          #+#    #+#             */
/*   Updated: 2021/12/02 05:41:59 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlst.h"

void	node_insert_between(t_node *to_insert, t_node *left, t_node *right)
{
	if (left == right)
	{
		right->prev = to_insert;
		right->next = to_insert;
		to_insert->prev = left;
		to_insert->next = left;
	}
	else
	{
		to_insert->prev = left;
		to_insert->next = right;
		left->next = to_insert;
		right->prev = to_insert;
	}
}
