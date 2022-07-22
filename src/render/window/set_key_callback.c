/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_key_callback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/22 22:24:45 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "render/window.h"
#include "mlx.h"

void	window_set_keydown_callback(int (*callback)(int))
{
	mlx_hook(_window()->core, 2, 1L << 0, callback, NULL);
}

void	window_set_keyup_callback(int (*callback)(int))
{
	mlx_hook(_window()->core, 3, 1L << 1, callback, NULL);
}
