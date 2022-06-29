/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_bubble_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 04:30:52 by nsierra-          #+#    #+#             */
/*   Updated: 2021/12/02 05:28:13 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlst.h"

void	lst_bubble_sort(t_lst *lst, int (*cmp)(void *, void *))
{
	int		sorted;
	t_node	*cursor;

	sorted = 0;
	if (lst->size <= 1)
		return ;
	while (!sorted)
	{
		cursor = lst_node_front(lst);
		sorted = 1;
		while (42)
		{
			if (cursor->next == lst_node_front(lst))
				break ;
			if (cmp(cursor->data, cursor->next->data) > 0)
			{
				node_swap(cursor, cursor->next);
				sorted = 0;
			}
			cursor = cursor->next;
		}
	}
}
