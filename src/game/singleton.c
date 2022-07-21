/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:34:35 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/21 22:16:22 by nsierra-         ###   ########.fr       */
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
	return (&_game()->map);
}

t_window	*_window(void)
{
	return (&_game()->window);
}

t_player	*_player(void)
{
	return (&_game()->player);
}

t_input	*_input(void)
{
	return (&_game()->input);
}
