/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fterr_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:26:09 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 14:36:09 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fterr.h"
#include <stdlib.h>

static void	free_error(void *error_raw)
{
	t_fterr	*error;

	error = (t_fterr *)error_raw;
	if (error->data_free != NULL)
		error->data_free(error->data);
	free(error);
}

void	fterr_destroy(void)
{
	t_lst	*e_list;

	e_list = fterr_get_list();
	if (e_list == NULL)
		return ;
	lst_destroy_nodes(e_list, free_error);
}
