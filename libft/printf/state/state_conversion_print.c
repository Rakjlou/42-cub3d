/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_conversion_print.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:11:04 by nsierra-          #+#    #+#             */
/*   Updated: 2021/12/02 02:34:09 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static void	dispatch(t_printf *state)
{
	void		(*callback[9])(t_printf *state);
	t_printf_op	*op;

	op = &state->op;
	callback[0] = print_character;
	callback[1] = print_string;
	callback[2] = print_pointer;
	callback[3] = print_int;
	callback[4] = print_int;
	callback[5] = print_unsigned_int;
	callback[6] = print_hex_lowercase;
	callback[7] = print_hex_uppercase;
	callback[8] = print_flag;
	callback[ft_strchr(CONV_SPECIFIERS, op->type) - CONV_SPECIFIERS](state);
}

const char	*state_conversion_print(const char *format, t_printf *state)
{
	state->current = STATE_DEFAULT;
	if (ft_strchr(CONV_SPECIFIERS, *format) == NULL)
	{
		state->current = STATE_WRONG_FLAG;
		return (format);
	}
	state->op.type = *format;
	dispatch(state);
	return (++format);
}
