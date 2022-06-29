/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:19:45 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 20:01:53 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

void	_ftprintf_write(t_printf *state, const char *str, size_t len)
{
	unsigned int	i;
	ssize_t			write_return;

	if (state->fd >= 0)
	{
		write_return = write(state->fd, str, (size_t)len);
		if (write_return > 0)
			state->bytes_printed += (int)write_return;
	}
	else if (state->fd == -42)
	{
		i = 0;
		while (state->wbuf_cursor < state->wbuf_size - 1
			&& i < (unsigned int)len)
			state->wbuf[state->wbuf_cursor++] = str[i++];
		state->wbuf[state->wbuf_cursor] = '\0';
		state->bytes_printed += i;
	}
}
