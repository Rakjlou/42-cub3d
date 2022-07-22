/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:26:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/22 22:40:37 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "bool.h"

typedef struct s_input
{
	t_bool	forward;
	t_bool	left;
	t_bool	right;
	t_bool	backward;
	t_bool	rotate_left;
	t_bool	rotate_right;
}	t_input;

t_input	*_input(void);

void	input_init(void);
void	input_debug(void);

#endif
