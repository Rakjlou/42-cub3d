/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:55:44 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/12 17:56:50 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef int	t_color;

typedef enum e_color_component
{
	ALPHA = 0xFF000000,
	RED = 0x00FF0000,
	GREEN = 0x0000FF00,
	BLUE = 0x000000FF
}	t_color_component;

typedef struct s_color_channels
{
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color_channels;

void	color_channels(t_color color, t_color_channels *channel);

t_color	color_build(
			unsigned char red,
			unsigned char green,
			unsigned char blue,
			unsigned char alpha);

t_color	color_build_str(
			char *red,
			char *green,
			char *blue,
			char *alpha);

#endif
