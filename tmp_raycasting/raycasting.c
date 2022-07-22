/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddordain <ddordain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:54:46 by ddordain          #+#    #+#             */
/*   Updated: 2022/07/22 17:35:47 by ddordain         ###   ########.fr       */
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

typedef struct s_mlx_data
{
	void	*mlx; // init of MLX
	char	*name;
	void	*img;
	char	*addr;
	int		bpp;
	int		size_l;
	int		endian;
	void	*mlx_win;
	float	px; // player x pos
	float	py; // player y pos
}				t_mlx_data;

// -=====================================================================================================

t_mlx_data	*_mlx_data(void)
{
	static t_bool	first = TRUE;
	static t_mlx_data	mlx_data;

	if (first == TRUE)
	{
		ft_bzero(&mlx_data, sizeof(mlx_data));
		first == FALSE;
	}
	return (&mlx_data);
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
	mlx_data->px = 300;
	mlx_data->py = 300;
}

void	display_character(void)
{

}

int	main(void)
{
	t_mlx_data	*mlx_data;

	mlx_data = _mlx_data();
	init_mlx();
	mlx_loop(mlx_data->mlx);
}