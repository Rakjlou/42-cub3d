/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_node_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 02:57:36 by nsierra-          #+#    #+#             */
/*   Updated: 2021/12/02 06:02:32 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlst.h"

static t_node	*reg_search(t_lst *lst, size_t pos)
{
	t_node			*cursor;
	size_t			i;

	cursor = lst->first;
	i = 0;
	while (i++ < pos)
		cursor = cursor->next;
	return (cursor);
}

static t_node	*rev_search(t_lst *lst, size_t pos, size_t offset)
{
	t_node			*cursor;

	cursor = lst_node_back(lst);
	while (offset-- > pos)
		cursor = cursor->prev;
	return (cursor);
}

t_node	*lst_node_at(t_lst *lst, size_t pos)
{
	if (pos >= lst->size)
		return (NULL);
	else if (pos == 0)
		return (lst->first);
	else if (pos == lst->size - 1)
		return (lst_node_back(lst));
	else if (pos <= (lst->size / 2))
		return (reg_search(lst, pos));
	else
		return (rev_search(lst, pos, lst->size - 1));
}
