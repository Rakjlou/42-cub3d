/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pop_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 04:12:17 by nsierra-          #+#    #+#             */
/*   Updated: 2021/12/02 06:16:12 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlst.h"

void	*lst_pop_back(t_lst *lst, void (*del)(void *))
{
	t_node				*last;

	if (lst->size == 0)
		return (NULL);
	last = lst_node_back(lst);
	if (last == lst_node_front(lst))
		lst->first = NULL;
	--lst->size;
	return (node_destroy(&last, del));
}
