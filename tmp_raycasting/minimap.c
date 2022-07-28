/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddordain <ddordain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:54:46 by ddordain          #+#    #+#             */
/*   Updated: 2022/07/25 15:33:10 by ddordain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// all data needed by mlx 

#include <math.h>
#include "libft.h"
#include <stdio.h>
#include <mlx.h>

#define WIDTH 1024
#define HEIGHT 512
#define TITLE "Cub3d by Big Macaque & Double Whooper"

#define YELLOW 0xFFFF00
#define WHITE 0xFFFFFF
#define BLUE 0x0000FF
#define GREEN 0x00FF00
#define GREY 0x808080

#define ESC 65307
#define LEFT 65361
#define RIGHT 65363
#define UP 65362
#define DOWN 65364

typedef struct	s_player
{
	int	x;
	int	y;
	int	width;
	int	height;
	int color;
}	t_player;

typedef struct	s_mlx_data
{
	void		*mlx; // init of MLX
	void		*mlx_win;
	char		*name;
	void		*img;
	char		*addr;
	int			bpp;
	int			size_l;
	int			endian;
	t_player	player;
}				t_mlx_data;



// -=====================================================================================================

t_mlx_data	*_mlx_data(void)
{
	static t_bool	first = TRUE;
	static t_mlx_data	mlx_data;

	if (first == TRUE)
	{
		ft_bzero(&mlx_data, sizeof(mlx_data));
		first = FALSE;
	}
	return (&mlx_data);
}

int render_player(void)
{
	t_mlx_data	*mlx_data;
	int			i;
	int			j;
	t_player	player;

	mlx_data = _mlx_data();
	player = mlx_data->player;
	if (mlx_data->mlx_win == NULL)
		return (1);
	i = player.y;
	while (i < player.y + player.height)
	{
		j = player.x;
		while (j < player.x + player.width)
			img_pxl_put(j++, i, player.color);
		++i;
	}
	return (0);
}

void	img_pxl_put(int x, int y, int color)
{
	char		*pixel;
	int			i;
	t_mlx_data	*mlx_data;

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
	t_mlx_data *mlx_data;

	mlx_data = _mlx_data();
	mlx_data->mlx = mlx_init();
	mlx_data->mlx_win = mlx_new_window(mlx_data->mlx, WIDTH, HEIGHT, TITLE);
	mlx_data->img = mlx_new_image(mlx_data->mlx, WIDTH, HEIGHT);
	mlx_data->addr = mlx_get_data_addr(mlx_data->img, &mlx_data->bpp, \
								&mlx_data->size_l, &mlx_data->endian);
	mlx_data->player.x = 300;
	mlx_data->player.y = 300;
	mlx_data->player.color = YELLOW;
	mlx_data->player.height = 8;
	mlx_data->player.width = 8;
}

// -=====================================================================================================

void	display_background(void)
{
	t_mlx_data *mlx_data;
	int			i;
	int			j;

	mlx_data = _mlx_data();
	if (mlx_data->mlx_win == NULL)
		return ;
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
			img_pxl_put(j++, i, GREY);
		++i;
	}
}

void	display_player(void)
{
	t_mlx_data	*mlx_data;

	mlx_data = _mlx_data();
	render_player();
}

void	display(void)
{
	display_background();
	display_player();
}

// -=====================================================================================================

int	buttons(int key)
{
	t_mlx_data	*mlx_data;

	mlx_data = _mlx_data();
	if (key == ESC)
	{
		mlx_destroy_image(mlx_data->mlx, mlx_data->img);
		mlx_destroy_window(mlx_data->mlx, mlx_data->mlx_win);
		mlx_destroy_display(mlx_data->mlx);
		exit(0);
	}
	else if (key == LEFT)
		mlx_data->player.x -= 5;
	else if (key == UP)
		mlx_data->player.y -= 5;
	else if (key == RIGHT)
		mlx_data->player.x += 5;
	else if (key == DOWN)
		mlx_data->player.y += 5;
	display();
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win, mlx_data->img, 0, 0);
}


// -=====================================================================================================

int	main(void)
{
	t_mlx_data	*mlx_data;

	mlx_data = _mlx_data();
	init_mlx();
	display();
	mlx_hook(mlx_data->mlx_win, 2, 1L << 0, buttons, &mlx_data);
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win, mlx_data->img, 0, 0);
	mlx_loop(mlx_data->mlx);
}