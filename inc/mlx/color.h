/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:55:44 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/12 00:40:10 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef int	t_color;

typedef enum e_color_component
{
	RED = 0xFF000000,
	GREEN = 0x00FF0000,
	BLUE = 0x0000FF00,
	ALPHA = 0x000000FF
}	t_color_component;

t_color	color_build(
			unsigned char red,
			unsigned char green,
			unsigned char blue,
			unsigned char alpha);

#endif
