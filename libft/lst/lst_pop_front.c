/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pop_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 04:15:54 by nsierra-          #+#    #+#             */
/*   Updated: 2021/12/02 06:16:11 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlst.h"

void	*lst_pop_front(t_lst *lst, void (*del)(void *))
{
	t_node				*first;

	if (lst->first == NULL)
		return (NULL);
	first = lst_node_front(lst);
	if (first == lst_node_back(lst))
		lst->first = NULL;
	else
		lst->first = first->next;
	--lst->size;
	return (node_destroy(&first, del));
}
