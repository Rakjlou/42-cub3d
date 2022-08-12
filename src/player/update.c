/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/12 15:06:48 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "input.h"

static void	update_movement(void)
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

void	player_update(void)
{
	update_movement();
}
