/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 04:33:32 by nsierra-          #+#    #+#             */
/*   Updated: 2021/12/02 05:32:08 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlst.h"
#include "ftprintf.h"

void	lst_print(t_lst *lst, void (*print_f)(void *), int mode)
{
	t_node	*cursor;
	size_t	i;

	i = 0;
	cursor = lst_node_front(lst);
	while (i++ < lst->size)
	{
		if (mode == 1)
		{
			ftprintf("----------\n");
			ftprintf("Position : %d\n", (int)(i - 1));
			ftprintf("Data : ");
		}
		print_f(cursor->data);
		if (mode == 0)
			ftprintf("\n");
		if (mode == 1)
			ftprintf("\n----------\n");
		cursor = cursor->next;
	}
}
