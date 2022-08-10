/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:26:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/10 18:29:27 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define PLAYER_DEFAULT_PLANE 0.66
# define PLAYER_DEFAULT_SPEED 0.05
# define PLAYER_DEFAULT_ROTATION_SPEED 0.05

# include "vectors.h"

typedef struct s_player
{
	t_dvector	pos;
	t_dvector	dir;
	t_dvector	plane;
	double		speed;
	double		rotation_speed;
}	t_player;

t_player	*_player(void);

void	player_init(void);
void	player_debug(void);

#endif
