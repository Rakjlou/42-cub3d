/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_conversion_flags.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:11:04 by nsierra-          #+#    #+#             */
/*   Updated: 2021/12/02 02:34:10 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

const char	*state_conversion_flags(const char *format, t_printf *state)
{
	ft_bzero(&state->op, sizeof(t_printf_op));
	state->op.start = format++;
	while (*format && ft_strchr(FLAGS, *format) != NULL)
	{
		if (*format == ' ')
			state->op.blank = TRUE;
		else if (*format == '+')
			state->op.force_sign = TRUE;
		else if (*format == '-')
			state->op.justified_left = TRUE;
		else if (*format == '0')
			state->op.zero_padded = TRUE;
		else if (*format == '#')
			state->op.alternative = TRUE;
		format++;
	}
	state->current = STATE_CONVERSION_LENGTH;
	if (*format == '\0')
		state->current = STATE_WRONG_FLAG;
	return (format);
}
