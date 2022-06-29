/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 04:26:39 by nsierra-          #+#    #+#             */
/*   Updated: 2021/12/02 06:16:11 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlst.h"

void	*lst_remove(t_lst *lst, size_t pos, void (*del)(void *))
{
	t_node				*cursor;

	if (pos >= lst->size)
		return (0);
	cursor = lst_node_at(lst, pos);
	if (pos == 0)
		lst->first = cursor->next;
	if (lst_node_front(lst) == lst_node_back(lst))
		lst->first = NULL;
	--lst->size;
	return (node_destroy(&cursor, del));
}
