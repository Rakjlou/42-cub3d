/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:26:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/12 12:10:00 by nsierra-         ###   ########.fr       */
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
	int	column;
	int	line_height;
	int	draw_start;
	int	draw_end;
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

void	raycast_wall_from_wcolumn(t_wall *wall, int column);

void	ray_init(t_ray *ray, int column);
void	ray_compute_side_dist(t_ray *r);
void	ray_compute_length(t_ray *ray);
void	ray_hit(t_ray *ray);

#endif
