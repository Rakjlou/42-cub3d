/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:26:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/13 20:21:44 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# define MINIMAP_OFFSET 10
# define MINIMAP_COLLIDER_COLOR 0x7FFFFFFF
# define MINIMAP_PLAYER_DOT_COLOR 0xC8F87CA

# include "render/rect.h"

typedef struct s_minimap
{
	int		size;
	t_rect	zone;
}	t_minimap;

void	minimap_render(void);
void	minimap_render_colliders(t_minimap *mmap);

#endif
