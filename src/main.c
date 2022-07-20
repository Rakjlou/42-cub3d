/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/21 00:27:06 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "errors.h"
#include "game.h"

int	main(int ac, char **av)
{
	if (!errors_register())
		return (perror("cub3d"), EXIT_FAILURE);
	else if (ac < 2 || ac > 2)
		return (fterr_set_error(E_USAGE), FALSE);
	else if (!game_init(av[1]))
		return (fterr_print(), fterr_destroy(), game_destroy(), EXIT_FAILURE);
	ft_putendl_fd("BONJOUR MONDE", 2);
	fterr_destroy();
	game_destroy();
	return (0);
}
