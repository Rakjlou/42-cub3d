/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/12 00:43:24 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/color.h"

t_color	color_build(
	unsigned char red,
	unsigned char green,
	unsigned char blue,
	unsigned char alpha)
{
	t_color	color;

	color = 0;
	color = red | (green << 8) | (blue << 16) | (alpha << 24);
	return (color);
}
