/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fterr_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:17:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 14:21:13 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fterr.h"

t_fterr	*fterr_get(t_fterr_code code)
{
	t_iter	iter;
	t_fterr	*error;
	t_lst	*e_list;

	e_list = fterr_get_list();
	if (e_list == NULL)
		return (NULL);
	iter_init(&iter, e_list, ASC);
	while (iter_next(&iter))
	{
		error = (t_fterr *)iter.data;
		if (error->code == code)
			return (error);
	}
	return (NULL);
}
