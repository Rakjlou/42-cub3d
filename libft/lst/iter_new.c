/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 05:00:45 by nsierra-          #+#    #+#             */
/*   Updated: 2021/12/02 06:00:16 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlst.h"

t_iter	*iter_new(t_lst *lst, t_lst_direction dir)
{
	t_iter	*new_it;

	new_it = ft_calloc(1, sizeof(t_iter));
	if (new_it == NULL)
		return (NULL);
	iter_init(new_it, lst, dir);
	return (new_it);
}
