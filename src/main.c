/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/01 16:03:47 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "errors.h"
#include "fterr.h"
#include "map/map.h"

static t_bool	init(int ac, char **av)
{
	(void)av;
	if (ac < 2 || ac > 2)
		return (fterr_set_error(E_USAGE), FALSE);
	else if (!map_init(av[1]))
		return (FALSE);
	return (TRUE);
}

int	main(int ac, char **av)
{
	if (!errors_register())
		return (perror("cub3d"), EXIT_FAILURE);
	else if (!init(ac, av))
		return (fterr_print(), fterr_destroy(), EXIT_FAILURE);
	ft_putendl_fd("BONJOUR MONDE", 2);
	return (0);
}
