/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fterr_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:42:50 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 14:18:46 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fterr.h"

void	fterr_set(t_fterr_code code, void *data, void (*data_free)(void *))
{
	t_fterr	*error;

	error = fterr_get(code);
	if (error == NULL)
		return ;
	if (error->data_free != NULL)
		error->data_free(error->data);
	error->data = data;
	error->data_free = data_free;
	fterr_set_current(error);
}

void	fterr_set_error(t_fterr_code code)
{
	fterr_set(code, NULL, NULL);
}
