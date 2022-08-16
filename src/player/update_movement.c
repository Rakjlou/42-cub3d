/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/15 22:24:18 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/window.h"
#include "player.h"
#include "input.h"

#include <stdio.h>
#include <math.h>

void	player_update_movement(void)
{
	t_input	*input;

	input = _input();
	if (input->forward && !input->backward)
		player_move_forward();
	if (input->backward && !input->forward)
		player_move_backward();
	if (input->left && !input->right)
		player_move_left();
	if (input->right && !input->left)
		player_move_right();
	if (input->rotate_left && !input->rotate_right)
		player_rotate_left();
	if (input->rotate_right && !input->rotate_left)
		player_rotate_right();
}
