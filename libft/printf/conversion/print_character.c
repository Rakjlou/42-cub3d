/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:15:41 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 19:46:02 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include <unistd.h>

static void	print_padding(t_printf *state, size_t size)
{
	size_t	i;

	i = 0;
	while (i++ < size)
		_ftprintf_write(state, " ", 1);
}

void	print_character(t_printf *state)
{
	int				raw;
	unsigned char	to_print;

	raw = va_arg(state->args, int);
	to_print = (unsigned int)raw;
	if (state->op.length == FALSE || state->op.length_value < 2)
	{
		_ftprintf_write(state, (char *)&to_print, 1);
		return ;
	}
	else if (state->op.justified_left == TRUE)
	{
		_ftprintf_write(state, (char *)&to_print, 1);
		print_padding(state, state->op.length_value - 1);
	}
	else
	{
		print_padding(state, state->op.length_value - 1);
		_ftprintf_write(state, (char *)&to_print, 1);
	}
}
