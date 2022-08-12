/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:26:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/11 23:30:56 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "vectors.h"
# include "bool.h"

/*
struct s_raycasting
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	deltaDistX;
	double	deltaDistY;
	double	sideDistX;
	double	sideDistY;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	double	perpWallDist;
	double	lineHeight;
	double	drawStart;
	double	drawEnd;
	int		color;
}	t_raycasting;
*/

typedef struct s_tile	t_tile;

typedef struct s_wall
{
	int		column;
	int		line_height;
	double	draw_start;
	double	draw_end;
}	t_wall;

typedef struct s_ray
{
	t_bool		hit;
	t_dvector	dir;
	t_dvector	delta_dist;
	t_dvector	side_dist;
	t_ivector	step_dir;
	t_ivector	tile;
	double		camera_x;
	double		length;
	int			side;
}	t_ray;

#endif
