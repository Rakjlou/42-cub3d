/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_wrong_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:29:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 19:55:55 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include <unistd.h>

const char	*state_wrong_flag(const char *format, t_printf *state)
{
	const char	*returned;

	returned = state->op.start;
	ft_bzero(&state->op, sizeof(t_printf_op));
	_ftprintf_write(state, "%", 1);
	state->current = STATE_DEFAULT;
	(void)format;
	return (++returned);
}
