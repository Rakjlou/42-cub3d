/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:26:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/12 14:21:54 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define PLAYER_START_POS_OFFSET 0.51
# define PLAYER_DEFAULT_FOV 0.66
# define PLAYER_DEFAULT_SPEED 0.05
# define PLAYER_DEFAULT_ROTATION_SPEED 0.05

# include "vectors.h"

typedef struct s_player
{
	t_dvector	pos;
	t_dvector	dir;
	t_dvector	fov;
	double		speed;
	double		rotation_speed;
}	t_player;

t_player	*_player(void);

void		player_init(void);
void		player_debug(void);

#endif
