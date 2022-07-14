/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/14 01:58:01 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/color.h"
#include "ftprintf.h"

t_color	color_build(
	unsigned char red,
	unsigned char green,
	unsigned char blue,
	unsigned char alpha)
{
	t_color	color;

	color = 0;
	color = (alpha << 24) | (red << 16) | (green << 8) | blue;
	return (color);
}