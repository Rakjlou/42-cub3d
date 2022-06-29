/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_data_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 03:04:42 by nsierra-          #+#    #+#             */
/*   Updated: 2021/12/02 06:11:25 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlst.h"

void	*lst_data_at(t_lst *lst, size_t pos)
{
	t_node	*node;

	node = lst_node_at(lst, pos);
	if (node == NULL)
		return (NULL);
	return (node->data);
}
