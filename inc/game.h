/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:26:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/11 22:42:31 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "map/map.h"
# include "render/window.h"
# include "player.h"
# include "input.h"
# include "libft.h"

typedef struct s_game
{
	t_map		map;
	t_window	window;
	t_player	player;
	t_input		input;
}	t_game;

t_game	*_game(void);

t_bool	game_init(char *mapfile);
void	game_destroy(void);
void	game_loop(void);
int		game_loop_callback(void);

#endif
