/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 04:49:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/31 14:26:09 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlst.h"
#include <stdlib.h>

void	lst_destroy_nodes(t_lst *lst, void (*del)(void *))
{
	void	*data;

	while (42)
	{
		data = lst_pop_back(lst, NULL);
		if (data == NULL)
			break ;
		if (del)
			del(data);
	}
}

void	lst_destroy(t_lst **lst, void (*del)(void *))
{
	lst_destroy_nodes(*lst, del);
	free(*lst);
	*lst = NULL;
}
