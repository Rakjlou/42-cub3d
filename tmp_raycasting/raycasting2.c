/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddordain <ddordain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:35:17 by ddordain          #+#    #+#             */
/*   Updated: 2022/07/28 17:00:25 by ddordain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>

#define WIDTH 1024
#define HEIGHT 512
#define TITLE "Cub3d by Big Macaque & Double Whooper"

#define YELLOW 0xFFFF00
#define WHITE 0xFFFFFF
#define BLUE 0x0000FF
#define GREEN 0x00FF00
#define GREY 0x808080
#define BLACK 0x000000

#define ESC 65307
#define LEFT 65361
#define RIGHT 65363
#define UP 65362
#define DOWN 65364

#define mapWidth 24
#define mapHeight 24
#define width 800
#define height 800

int	worldMap[24][24] = {
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
						};

typedef struct	s_info
{
	// part dda
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double	moveSpeed;
	double	rotSpeed;

	//part mlx
	void	*mlx;
	void	*mlx_win;
	char	*name;
	void	*img;
	char	*addr;
	int		bpp;
	int		size_l;
	int		endian;	
}				t_info;

typedef struct	s_dda
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	mapX;
	double	mapY;
	double	sideDistX;
	double	sideDistY;
	int		hit;
	int		side;
	double	lineHeight;
	double	drawStart;
	double	drawEnd;
}	t_dda;

t_info	*_mlx_data(void)
{
	static t_bool	first = TRUE;
	static t_info	mlx_data;

	if (first == TRUE)
	{
		ft_bzero(&mlx_data, sizeof(mlx_data));
		first = FALSE;
	}
	return (&mlx_data);
}

void	img_pxl_put(int x, int y, int color)
{
	char		*pixel;
	int			i;
	t_info	*mlx_data;

	mlx_data = _mlx_data();
	i = mlx_data->bpp - 8;
	pixel = mlx_data->addr + (y * mlx_data->size_l + x * (mlx_data->bpp / 8));
	while (i >= 0)
	{
		if (mlx_data->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (mlx_data->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	init_mlx(void)
{
	t_info *mlx_data;

	mlx_data = _mlx_data();
	mlx_data->mlx = mlx_init();
	mlx_data->mlx_win = mlx_new_window(mlx_data->mlx, width, height, TITLE);
	mlx_data->img = mlx_new_image(mlx_data->mlx, width, height);
	mlx_data->addr = mlx_get_data_addr(mlx_data->img, &mlx_data->bpp, \
								&mlx_data->size_l, &mlx_data->endian);
	mlx_data->posX = 12;
	mlx_data->posY = 5;
	mlx_data->dirX = -1;
	mlx_data->dirY = 0;
	mlx_data->planeX = 0;
	mlx_data->planeY = 0.66;
	mlx_data->moveSpeed = 0.05;
	mlx_data->rotSpeed = 0.05;
}

void	verLine(int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		img_pxl_put(x, y, color);
		y++;
	}
}

void	calc(void)
{
	t_info *info;
	int	x;

	info = _mlx_data();
	x = 0;
	while (x < width)
	{
		double cameraX = 2 * x / (double)width - 1;
		double rayDirX = info->dirX + info->planeX * cameraX;
		double rayDirY = info->dirY + info->planeY * cameraX;

		int mapX = (int)info->posX;
		int mapY = (int)info->posY;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		 //length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;
		
		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;
		
		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (info->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - info->posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (info->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - info->posY) * deltaDistY;
		}

		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (worldMap[mapX][mapY] > 0) hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - info->posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - info->posY + (1 - stepY) / 2) / rayDirY;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(height / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + height / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + height / 2;
		if(drawEnd >= height)
			drawEnd = height - 1;

		int	color;
		if (worldMap[mapY][mapX] == 1)
			color = 0xFF0000;
		else if (worldMap[mapY][mapX] == 2)
			color = 0x00FF00;
		else if (worldMap[mapY][mapX] == 3)
			color = 0x0000FF;
		else if (worldMap[mapY][mapX] == 4)
			color = 0xFFFFFF;
		else
			color = 0xFFFF00;
		
		if (side == 1)
			color = color / 2;

		verLine(x, drawStart, drawEnd, color);
		
		x++;
	}
}

int	key_press(int key)
{
	t_info *info;

	info = _mlx_data();
	if (key == UP)
	{
		puts("up");
		printf("%f\n", info->posX);
		if (!worldMap[(int)(info->posX + info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX += info->dirX * info->moveSpeed;
		if (!worldMap[(int)(info->posX)][(int)(info->posY + info->dirY * info->moveSpeed)])
			info->posY += info->dirY * info->moveSpeed;
		printf("%f\n", info->posX);
	}
	//move backwards if no wall behind you
	if (key == DOWN)
	{
		if (!worldMap[(int)(info->posX - info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX -= info->dirX * info->moveSpeed;
		if (!worldMap[(int)(info->posX)][(int)(info->posY - info->dirY * info->moveSpeed)])
			info->posY -= info->dirY * info->moveSpeed;
	}
	//rotate to the right
	if (key == RIGHT)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(-info->rotSpeed) - info->dirY * sin(-info->rotSpeed);
		info->dirY = oldDirX * sin(-info->rotSpeed) + info->dirY * cos(-info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
		info->planeY = oldPlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
	}
	//rotate to the left
	if (key == LEFT)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
		info->dirY = oldDirX * sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
		info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
	}
	if (key == ESC)
		exit(0);
	display();
	return (0);
}

void	display_background(void)
{
	t_info *mlx_data;
	int			i;
	int			j;

	mlx_data = _mlx_data();
	if (mlx_data->mlx_win == NULL)
		return ;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
			img_pxl_put(j++, i, BLACK);
		++i;
	}
}

void	display(void)
{
	t_info *info;

	info = _mlx_data();
	display_background();
	calc();
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->img, 0, 0);
}

int	main(void)
{
	t_info	*mlx_data;

	mlx_data = _mlx_data();
	init_mlx();
	display();
	mlx_hook(mlx_data->mlx_win, 2, 1L << 0, key_press, &mlx_data);
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win, mlx_data->img, 0, 0);
	mlx_loop(mlx_data->mlx);
}
