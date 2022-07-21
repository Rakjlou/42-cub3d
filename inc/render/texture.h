/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:26:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/21 19:52:26 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "libft.h"

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

#endif
