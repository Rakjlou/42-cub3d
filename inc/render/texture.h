/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:26:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/15 21:54:24 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "libft.h"
# include "render/color.h"

typedef struct s_texture
{
	char	*filename;
	char	*buffer;
	void	*image;
	int		width;
	int		height;
	int		depth;
	int		line_size;
	int		endian;
}	t_texture;

t_bool	texture_hydrate(t_texture *texture);
void	texture_destroy(t_texture *texture);

t_color	*texture_get_pixel(t_texture *texture, int line, int column);

#endif
