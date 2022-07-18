/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_metadata_errors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:07:37 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/18 22:33:16 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "map/map_validation.h"

t_bool	check_metadata_error(char **cmatrix, t_error_code error_code)
{
	if (cmatrix != NULL)
		ft_cmatrix_free(cmatrix);
	fterr_set_error(error_code);
	return (FALSE);
}

t_bool	check_metadata_error_printf(
	char **cmatrix,
	t_error_code error_code,
	char *data)
{
	fterr_set(error_code, ft_strdup(data), free);
	if (cmatrix != NULL)
		ft_cmatrix_free(cmatrix);
	return (FALSE);
}
