/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:34:35 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/11 22:51:31 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

t_game	*_game(void)
{
	static t_bool	first = TRUE;
	static t_game	game;

	if (first == TRUE)
	{
		ft_bzero(&game, sizeof(t_game));
		first = FALSE;
	}
	return (&game);
}

t_map	*_map(void)
{
	static t_map	*map = NULL;

	if (map == NULL)
		map = &_game()->map;
	return (map);
}

t_window	*_window(void)
{
	static t_window	*window = NULL;

	if (window == NULL)
		window = &_game()->window;
	return (window);
}

t_player	*_player(void)
{
	static t_player	*player = NULL;

	if (player == NULL)
		player = &_game()->player;
	return (player);
}

t_input	*_input(void)
{
	static t_input	*input = NULL;

	if (input == NULL)
		input = &_game()->input;
	return (input);
}
