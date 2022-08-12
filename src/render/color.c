/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/12 18:52:28 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/color.h"
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

unsigned char	color_component(t_color color, t_color_component component)
{
	if (component == ALPHA)
		return ((color & component) >> 24);
	else if (component == RED)
		return ((color & component) >> 16);
	else if (component == GREEN)
		return ((color & component) >> 8);
	else if (component == BLUE)
		return ((color & component) >> 0);
	return (0);
}

void	color_channels(t_color color, t_color_channels *channel)
{
	channel->a = color_component(color, ALPHA);
	channel->r = color_component(color, RED);
	channel->g = color_component(color, GREEN);
	channel->b = color_component(color, BLUE);
}
