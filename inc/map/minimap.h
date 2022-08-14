/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:26:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/14 13:31:29 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# define MINIMAP_OFFSET 10
# define MINIMAP_COLLIDER_COLOR 0x7FFFFFFF
# define MINIMAP_PLAYER_DOT_COLOR 0xA0000000
# define MINIMAP_PLAYER_DIR_COLOR 0xE0000000

# include "vectors.h"
# include "render/rect.h"

typedef struct s_minimap
{
	int			size;
	int			tile_size;
	t_rect		zone;
	t_ivector	center;
}	t_minimap;

void	minimap_render(void);
void	minimap_render_colliders(t_minimap *mmap);

#endif
