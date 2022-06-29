/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:47:20 by nsierra-          #+#    #+#             */
/*   Updated: 2021/11/24 20:24:02 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cursor;
	t_list	*to_del;

	cursor = *lst;
	while (cursor)
	{
		to_del = cursor;
		cursor = cursor->next;
		ft_lstdelone(to_del, del);
	}
	*lst = NULL;
}
