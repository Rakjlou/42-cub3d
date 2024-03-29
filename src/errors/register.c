/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:24:29 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/23 00:00:28 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "fterr.h"

/*
	"er" is short for error_register
	It's only to comply with 42
	Sorry
*/
static t_bool	er(
	t_fterr_code code,
	const char *message,
	void (*print)(t_fterr *))
{
	return (fterr_register(code, message, print) != NULL);
}

t_bool	errors_register(void)
{
	if (!er(E_USAGE, E_USAGE_MSG, NULL)
		|| !er(E_MALLOC, E_MALLOC_MSG, NULL)
		|| !er(E_MAP_CHAR, E_MAP_CHAR_MSG, NULL)
		|| !er(E_MAP_SPAWN_MISS, E_MAP_SPAWN_MISS_MSG, NULL)
		|| !er(E_MAP_SPAWN_EXTRA, E_MAP_SPAWN_EXTRA_MSG, NULL)
		|| !er(E_META_FORMAT, E_META_FORMAT_MSG, NULL)
		|| !er(E_MAP_HOLE, E_MAP_HOLE_MSG, NULL)
		|| !er(E_MLX_FAILURE, E_MLX_FAILURE_MSG, NULL)
		|| !er(E_MLX_XPM_FAILURE, E_MLX_XPM_FAILURE_MSG, NULL)
		|| !er(E_MAP_BIG, E_MAP_BIG_MSG, NULL)
		|| !er(E_META_MISSING, E_META_MISSING_MSG, fterr_default_printf)
		|| !er(E_COLOR_DEF, E_COLOR_DEF_MSG, fterr_default_printf)
		|| !er(E_COLOR_VAL, E_COLOR_VAL_MSG, fterr_default_printf)
		|| !er(E_MAP_EXT, E_MAP_EXT_MSG, fterr_default_printf)
		|| !er(E_MAP_EXT2, E_MAP_EXT2_MSG, fterr_default_printf)
		|| !er(E_META_INVALID, E_META_INVALID_MSG, fterr_default_printf)
		|| !er(E_MAP_OPEN, E_MAP_OPEN_MSG, fterr_default_printf)
		|| !er(E_MAP_EMPTY, E_MAP_EMPTY_MSG, fterr_default_printf))
	{
		fterr_destroy();
		return (FALSE);
	}
	return (TRUE);
}
