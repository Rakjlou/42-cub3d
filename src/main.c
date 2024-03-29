/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/10 18:26:35 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "errors.h"
#include "game.h"

int	main(int ac, char **av)
{
	if (!errors_register())
		return (perror("cub3d"), EXIT_FAILURE);
	else if (ac < 2 || ac > 2)
		return (ft_putendl_fd(E_USAGE_MSG, STDERR_FILENO), FALSE);
	else if (!game_init(av[1]))
		return (fterr_print(), fterr_destroy(), game_destroy(), EXIT_FAILURE);
	game_loop();
	fterr_destroy();
	game_destroy();
	return (0);
}
