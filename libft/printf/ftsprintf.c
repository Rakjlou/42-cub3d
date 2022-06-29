/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsprintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:13:29 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 20:00:02 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static void	init_state(t_printf *state, char *buffer, unsigned int size)
{
	state->fd = -42;
	state->wbuf = buffer;
	state->wbuf_size = size;
	state->wbuf_cursor = 0;
	state->current = STATE_DEFAULT;
	state->bytes_printed = 0;
	state->callback[STATE_DEFAULT] = state_default;
	state->callback[STATE_CONVERSION_FLAGS] = state_conversion_flags;
	state->callback[STATE_CONVERSION_LENGTH] = state_conversion_length;
	state->callback[STATE_CONVERSION_PRECISION] = state_conversion_precision;
	state->callback[STATE_CONVERSION_PRINT] = state_conversion_print;
	state->callback[STATE_WRONG_FLAG] = state_wrong_flag;
}

int	ftsprintf(char *buffer, size_t size, const char *format, ...)
{
	t_printf		state;
	unsigned int	current_state;

	if (format == NULL)
		return (-1);
	init_state(&state, buffer, size);
	va_start(state.args, format);
	while (state.current != STATE_END)
	{
		current_state = state.current;
		format = state.callback[current_state](format, &state);
	}
	va_end(state.args);
	return (state.bytes_printed);
}
