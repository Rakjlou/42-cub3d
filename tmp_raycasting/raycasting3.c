/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddordain <ddordain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:35:17 by ddordain          #+#    #+#             */
/*   Updated: 2022/08/02 17:03:53 by ddordain         ###   ########.fr       */
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

#define screenWidth 800
#define screenHeigth 800
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24
#define width 800
#define height 800

int	worldMap[mapWidth][mapHeight] =
						{
							{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
							{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
							{4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
							{4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
							{4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
							{4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
							{4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
							{4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
							{4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
							{4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
							{4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
							{4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
							{6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
							{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
							{6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
							{4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
							{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
							{4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
							{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
							{4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
							{4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
							{4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
							{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
							{4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
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
	int		texture[8][texHeight * texWidth];
	int		**buff;
}				t_info;

typedef struct	s_dda
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
}	t_dda;

typedef struct	s_texture
{
	int		texNum;
	double	wallX;
	int		texX;
	int		texY;
	double	step;
	double	texPos;
}	t_tex;

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

t_dda	*_dda(void)
{
	static t_bool	first = TRUE;
	static t_dda	dda;

	if (first == TRUE)
	{
		ft_bzero(&dda, sizeof(dda));
		first = FALSE;
	}
	return (&dda);
}

t_tex	*_tex(void)
{
	static t_bool	first = TRUE;
	static t_tex	tex;

	if (first == TRUE)
	{
		ft_bzero(&tex, sizeof(tex));
		first = FALSE;
	}
	return (&tex);
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

void	draw(void)
{
	t_info	*info;

	info = _mlx_data();
	int	y;
	int x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			info->addr[y * width * x] = info->buff[y][x];
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->img, 0, 0);
}

// void	verLine(int x, int y1, int y2, int color)
// {
	// int	y;
// 
	// y = y1;
	// while (y <= y2)
	// {
		// img_pxl_put(x, y, color);
		// y++;
	// }
// }

void	init_dda_parameter(t_info info, int x)
{
	t_dda	*dda;

	dda = _dda();
	dda->hit = 0;
	dda->cameraX = 2 * x / (double)width - 1;
	dda->rayDirX = info.dirX + info.planeX * dda->cameraX;
	dda->rayDirY = info.dirY + info.planeY * dda->cameraX;
	dda->mapX = (int)info.posX;
	dda->mapY = (int)info.posY;
	dda->deltaDistX = fabs(1 / dda->rayDirX);
	dda->deltaDistY = fabs(1 / dda->rayDirY);
}

void	compute_sidedistance(t_info info)
{
	t_dda	*dda;

	dda = _dda();
	if (dda->rayDirX < 0)
	{
		dda->stepX = -1;
		dda->sideDistX = (info.posX - dda->mapX) * dda->deltaDistX;
	}
	else
	{
		dda->stepX = 1;
		dda->sideDistX = (dda->mapX + 1.0 - info.posX) * dda->deltaDistX;
	}
	if (dda->rayDirY < 0)
	{
		dda->stepY = -1;
		dda->sideDistY = (info.posY - dda->mapY) * dda->deltaDistY;
	}
	else
	{
		dda->stepY = 1;
		dda->sideDistY = (dda->mapY + 1.0 - info.posY) * dda->deltaDistY;
	}
}

void	check_hit(t_info info)
{
	t_dda	*dda;

	dda = _dda();
	while (dda->hit == 0)
	{
		if (dda->sideDistX < dda->sideDistY)
		{
			dda->sideDistX += dda->deltaDistX;
			dda->mapX += dda->stepX;
			dda->side = 0;
		}
		else
		{
			dda->sideDistY += dda->deltaDistY;
			dda->mapY += dda->stepY;
			dda->side = 1;
		}
		if (worldMap[dda->mapX][dda->mapY] > 0)
			dda->hit = 1;
	}
}

void	compute_wall_distance(t_info info)
{
	t_dda	*dda;

	dda = _dda();
	if (dda->side == 0)
		dda->perpWallDist = (dda->mapX - info.posX + (1 - dda->stepX) / 2) / dda->rayDirX;
	else
		dda->perpWallDist = (dda->mapY - info.posY + (1 - dda->stepY) / 2) / dda->rayDirY;
	dda->lineHeight = (int)(height / dda->perpWallDist);
	dda->drawStart = -dda->lineHeight / 2 + height / 2;
	if (dda->drawStart < 0)
		dda->drawStart = 0;
	dda->drawEnd = dda->lineHeight / 2 + height / 2;
	if (dda->drawEnd >= height)
		dda->drawEnd = height - 1;
}


void	compute_texture(t_info info)
{
	t_dda	*d;
	t_tex	*t;

	d = _dda();
	t = _tex();
	t->texNum = worldMap[d->mapX][d->mapY];
	if (d->side == 0)
		t->wallX = info.posY + d->perpWallDist * d->rayDirY;
	else
		t->wallX = info.posX + d->perpWallDist * d->rayDirX;
	t->wallX -= floor(t->wallX);
	t->texX = (int)(t->wallX * (double)texWidth);
	if (d->side == 0 && d->rayDirX > 0)
		t->texX = texWidth - t->texX - 1;
	if (d->side == 1 && d->rayDirY < 0)
		t->texX = texWidth - t->texX - 1;
	t->step = 1.0 * texHeight / d->lineHeight;
	t->texPos = (d->drawStart - height / 2 + d->lineHeight / 2) * t->step;
}

void	cast_texture(t_info info, int x)
{
	t_dda	*d;
	t_tex	*t;
	int		y1;
	int		y2;

	d = _dda();
	t = _tex();
	y1 = (int)d->drawStart;
	y2 = (int)d->drawEnd;
	printf("%d\n", y1);
	while (y1 < y2)
	{
		t->texY = (int)t->texPos & (texHeight - 1);
		t->texPos += t->step;
		d->color = info.texture[t->texNum][texHeight * t->texY + t->texX];
		if (d->side == 1)
			d->color = (d->color >> 1) & 8355711;
		printf("y = %d, x = %d\n", y, x);
		info.buff[y1][x] = d->color;
		y1++;
	}
}

void	set_texture(void)
{
	t_info	*info;

	info = _mlx_data();
	info->buff = (int **)malloc(sizeof(int *) * height);
	for (int i = 0; i < height; i++)
	{
		info->buff[i] = (int *)malloc(sizeof(int) * width);
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			info->buff[i][j] = 0;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < texHeight * texWidth; j++)
		{
			info->texture[i][j] = 0;
		}
	}

	for (int x = 0; x < texWidth; x++)
	{
		for (int y = 0; y < texHeight; y++)
		{
			int xorcolor = (x * 256 / texWidth) ^ (y * 256 / texHeight);
			int ycolor = y * 256 / texHeight;
			int xycolor = y * 128 / texHeight + x * 128 / texWidth;
			info->texture[0][texWidth * y + x] = 65536 * 254 * (x != y && x != texWidth - y); //flat red texture with black cross
			info->texture[1][texWidth * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
			info->texture[2][texWidth * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
			info->texture[3][texWidth * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
			info->texture[4][texWidth * y + x] = 256 * xorcolor; //xor green
			info->texture[5][texWidth * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
			info->texture[6][texWidth * y + x] = 65536 * ycolor; //red gradient
			info->texture[7][texWidth * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
		}
	}	
}

// void color_wall(void)
// {
// 	t_dda	*dda;

// 	dda = _dda();
// 	if (worldMap[dda->mapY][dda->mapX] == 1)
// 		dda->color = 0xFF0000;
// 	else if (worldMap[dda->mapY][dda->mapX] == 2)
// 		dda->color = 0x00FF00;
// 	else if (worldMap[dda->mapY][dda->mapX] == 3)
// 		dda->color = 0x0000FF;
// 	else if (worldMap[dda->mapY][dda->mapX] == 4)
// 		dda->color = 0xFFFFFF;
// 	else
// 		dda->color = 0xFFFF00;
	
// 	if (dda->side == 1)
// 		dda->color = dda->color / 2;
// }

void	compute_raycasting(void)
{
	t_info *info;
	t_dda	*d;
	int	x;

	info = _mlx_data();
	d = _dda();
	x = 0;
	while (x < width)
	{
		init_dda_parameter(*info, x);
		compute_sidedistance(*info);
		check_hit(*info);
		compute_wall_distance(*info);
		// color_wall();
		// verLine(x, d->drawStart, d->drawEnd, d->color);
		compute_texture(*info);
		cast_texture(*info, x);
		x++;
	}
}

void	button_up(void)
{
	t_info	*info;

	info = _mlx_data();
	if (!worldMap[(int)(info->posX + info->dirX * info->moveSpeed)][(int)(info->posY)])
		info->posX += info->dirX * info->moveSpeed;
	if (!worldMap[(int)(info->posX)][(int)(info->posY + info->dirY * info->moveSpeed)])
		info->posY += info->dirY * info->moveSpeed;
}

void	button_down(void)
{
	t_info	*info;

	info = _mlx_data();
	if (!worldMap[(int)(info->posX - info->dirX * info->moveSpeed)][(int)(info->posY)])
		info->posX -= info->dirX * info->moveSpeed;
	if (!worldMap[(int)(info->posX)][(int)(info->posY - info->dirY * info->moveSpeed)])
		info->posY -= info->dirY * info->moveSpeed;	
}

void	button_right(void)
{
	t_info	*info;
	double oldDirX;
	double oldPlaneX;

	info = _mlx_data();
	oldDirX = info->dirX;
	info->dirX = info->dirX * cos(-info->rotSpeed) - info->dirY * sin(-info->rotSpeed);
	info->dirY = oldDirX * sin(-info->rotSpeed) + info->dirY * cos(-info->rotSpeed);
	oldPlaneX = info->planeX;
	info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
	info->planeY = oldPlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
}

void	button_left(void)
{
	t_info	*info;
	double	oldDirX;
	double	oldPlaneX;

	info = _mlx_data();
	oldDirX = info->dirX;
	info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
	info->dirY = oldDirX * sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);
	oldPlaneX = info->planeX;
	info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
	info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);	
}


// buttons feature
int	buttons(int key)
{
	if (key == UP)
		button_up();
	if (key == DOWN)
		button_down();
	if (key == RIGHT)
		button_right();
	if (key == LEFT)
		button_left();
	if (key == ESC)
		exit(0);
	display();
	return (0);
}

// temp : display of the background
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

// the display function.
void	display(void)
{
	t_info *info;

	info = _mlx_data();
	// display_background();
	compute_raycasting();
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->img, 0, 0);
}

// looping the display with mlx parameter
void	loop(void)
{
	t_info	*mlx_data;

	mlx_data = _mlx_data();
	init_mlx();
	display();
	mlx_hook(mlx_data->mlx_win, 2, 1L << 0, buttons, &mlx_data);
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win, mlx_data->img, 0, 0);
	mlx_loop(mlx_data->mlx);
}

int	main(void)
{
	set_texture();
	loop();
}
