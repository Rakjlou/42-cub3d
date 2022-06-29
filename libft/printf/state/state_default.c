/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_default.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:08:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 19:53:36 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ftprintf.h"
#include <unistd.h>

static int	get_state(const char token)
{
	if (token == CONVERSION_CHARACTER)
		return (STATE_CONVERSION_FLAGS);
	else if (token == '\0')
		return (STATE_END);
	return (STATE_DEFAULT);
}

const char	*state_default(const char *format, t_printf *state)
{
	int	i;

	i = 0;
	while (format[i] && format[i] != CONVERSION_CHARACTER)
		i++;
	if (i != 0)
		_ftprintf_write(state, format, i);
	state->current = get_state(format[i]);
	return (format + i);
}
