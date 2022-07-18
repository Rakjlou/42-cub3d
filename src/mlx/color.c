/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/18 21:36:09 by nsierra-         ###   ########.fr       */
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

t_color	color_build_str(
	char *red,
	char *green,
	char *blue,
	char *alpha)
{
	return (color_build(
			(unsigned char)ft_atoi(red),
			(unsigned char)ft_atoi(green),
			(unsigned char)ft_atoi(blue),
			(unsigned char)ft_atoi(alpha))
	);
}
