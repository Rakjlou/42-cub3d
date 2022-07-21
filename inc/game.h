/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:26:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/21 21:54:03 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "map/map.h"
# include "render/window.h"
# include "player.h"
# include "libft.h"

typedef struct s_game
{
	t_map		map;
	t_window	window;
	t_player	player;
}	t_game;

t_game	*_game(void);

t_bool	game_init(char *mapfile);
void	game_destroy(void);
void	game_loop(void);

#endif
