/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/22 22:39:40 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "ftprintf.h"

void	input_debug(void)
{
	ftfprintf(STDERR_FILENO, "Forward      %d\n", _input()->forward);
	ftfprintf(STDERR_FILENO, "Left         %d\n", _input()->left);
	ftfprintf(STDERR_FILENO, "Right        %d\n", _input()->right);
	ftfprintf(STDERR_FILENO, "Backward     %d\n", _input()->backward);
	ftfprintf(STDERR_FILENO, "Rotate Left  %d\n", _input()->rotate_left);
	ftfprintf(STDERR_FILENO, "Rotate Right %d\n", _input()->rotate_right);
}
